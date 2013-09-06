EXTRALIBS = -luuid
if FREEBSD
EXTRALIBS += -lexecinfo
endif
if LINUX
EXTRALIBS += -lrt
endif
if WITH_PROFILER
EXTRALIBS += -lprofiler
endif

LIBGLOBAL_LDA = libglobal.la $(PTHREAD_LIBS) -lm $(CRYPTO_LIBS) $(EXTRALIBS)

AM_COMMON_FLAGS = \
	-D__CEPH__ \
	-D_FILE_OFFSET_BITS=64 \
	-D_REENTRANT \
	-D_THREAD_SAFE \
	-D__STDC_FORMAT_MACROS \
	-D_GNU_SOURCE \
	-Wall \
	${WARN_TYPE_LIMITS} \
	${WARN_IGNORED_QUALIFIERS} \
	-Winit-self \
	-Wpointer-arith \
	-Werror=format-security \
	-fno-strict-aliasing \
	-fsigned-char
if !CLANG
    AM_COMMON_FLAGS += -rdynamic
endif

AM_CFLAGS = $(AM_COMMON_FLAGS)
AM_CXXFLAGS = \
	@AM_CXXFLAGS@ \
	$(AM_COMMON_FLAGS) \
	-DCEPH_LIBDIR=\"${libdir}\" \
	-Wnon-virtual-dtor \
	-Wno-invalid-offsetof

if ENABLE_FPU_NEON
AM_CFLAGS += -mfpu=neon
AM_CXXFLAGS += -mfpu=neon
endif

if !CLANG
    AM_CXXFLAGS += -Wstrict-null-sentinel
endif
# note: this is position dependant, it affects the -l options that
# come after it on the command line. when you use ${AM_LDFLAGS} in
# later rules, take care where you place it. for more information, see
# http://blog.flameeyes.eu/2008/11/19/relationship-between-as-needed-and-no-undefined-part-1-what-do-they-do
# http://blog.flameeyes.eu/2008/11/20/misguided-link-and-as-needed
# http://www.gentoo.org/proj/en/qa/asneeded.xml
# http://gcc.gnu.org/ml/gcc-help/2010-12/msg00338.html
# http://sigquit.wordpress.com/2011/02/16/why-asneeded-doesnt-work-as-expected-for-your-libraries-on-your-autotools-project/
AM_LDFLAGS = -Wl,--as-needed

if USE_BOOST_SPIRIT_OLD_HDR
AM_CXXFLAGS += -DUSE_BOOST_SPIRIT_OLD_HDR
endif

if WITH_LIBATOMIC
AM_LDFLAGS += -latomic_ops
endif

if ENABLE_COVERAGE
AM_CFLAGS += -fprofile-arcs -ftest-coverage
AM_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0
EXTRALIBS += -lgcov
endif

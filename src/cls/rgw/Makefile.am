include $(top_srcdir)/src/common.mk
include $(top_srcdir)/src/cls/common.mk

radoslib_LTLIBRARIES = libcls_rgw.la

libcls_rgw_la_SOURCES = \
	cls_rgw.cc \
	cls_rgw_ops.cc \
	cls_rgw_types.cc \
	$(top_srcdir)/src/common/ceph_json.cc

libcls_rgw_la_LIBADD = $(PTHREAD_LIBS) $(EXTRALIBS) $(top_builddir)/src/json_spirit/libjson_spirit.la
libcls_rgw_la_LDFLAGS = ${AM_LDFLAGS} -version-info 1:0:0 -export-symbols-regex '.*__cls_.*'

noinst_LIBRARIES = libcls_rgw_client.a

libcls_rgw_client_a_SOURCES =  \
	cls_rgw_client.cc \
	cls_rgw_types.cc \
	cls_rgw_ops.cc

# avoid clash with .o files from shared files
libcls_rgw_client_a_CXXFLAGS = $(AM_CXXFLAGS)

noinst_HEADERS = \
	cls_rgw_client.h \
	cls_rgw_ops.h \
	cls_rgw_types.h

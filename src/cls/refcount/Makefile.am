include $(top_srcdir)/src/common.mk
include $(top_srcdir)/src/cls/common.mk

radoslib_LTLIBRARIES = libcls_refcount.la

libcls_refcount_la_SOURCES = \
	cls_refcount.cc \
	cls_refcount_ops.cc \
	$(top_srcdir)/src/common/ceph_json.cc \
	$(top_srcdir)/src/json_spirit/json_spirit_reader.cpp \
	$(top_srcdir)/src/json_spirit/json_spirit_writer.cpp \
	$(top_srcdir)/src/json_spirit/json_spirit_value.cpp
libcls_refcount_la_LIBADD = $(PTHREAD_LIBS) $(EXTRALIBS)
libcls_refcount_la_LDFLAGS = ${AM_LDFLAGS} -version-info 1:0:0 -export-symbols-regex '.*__cls_.*'

noinst_LIBRARIES = libcls_refcount_client.a

libcls_refcount_client_a_SOURCES =  \
	cls_refcount_client.cc \
	cls_refcount_ops.cc
# build with prefix to avoid clash with cls_refcount_ops.o in libcls_refcount.la
libcls_refcount_client_a_CXXFLAGS = $(AM_CXXFLAGS)

noinst_HEADERS = \
	cls_refcount_ops.h \
	cls_refcount_client.h

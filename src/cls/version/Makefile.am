include $(top_srcdir)/src/common.mk
include $(top_srcdir)/src/cls/common.mk

radoslib_LTLIBRARIES = libcls_version.la

libcls_version_la_SOURCES = cls_version.cc
libcls_version_la_LIBADD = $(PTHREAD_LIBS) $(EXTRALIBS)
libcls_version_la_LDFLAGS = ${AM_LDFLAGS} -version-info 1:0:0 -export-symbols-regex '.*__cls_.*'

noinst_LIBRARIES = libcls_version_client.a

libcls_version_client_a_SOURCES = \
	cls_version_client.cc \
	cls_version_types.cc

noinst_HEADERS = \
	cls_version_types.h\
	cls_version_ops.h\
	cls_version_client.h

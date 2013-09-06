include $(top_srcdir)/src/common.mk
include $(top_srcdir)/src/cls/common.mk

radoslib_LTLIBRARIES = libcls_statelog.la

libcls_statelog_la_SOURCES = cls_statelog.cc
libcls_statelog_la_LIBADD = $(PTHREAD_LIBS) $(EXTRALIBS)
libcls_statelog_la_LDFLAGS = ${AM_LDFLAGS} -version-info 1:0:0 -export-symbols-regex '.*__cls_.*'

noinst_LIBRARIES = libcls_statelog_client.a

libcls_statelog_client_a_SOURCES = \
	cls_statelog_client.cc

noinst_HEADERS = \
	cls_statelog_types.h \
	cls_statelog_ops.h \
	cls_statelog_client.h

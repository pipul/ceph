include $(top_srcdir)/src/common.mk
include $(top_srcdir)/src/cls/common.mk

radoslib_LTLIBRARIES = libcls_log.la

libcls_log_la_SOURCES = cls_log.cc
libcls_log_la_LIBADD = $(PTHREAD_LIBS) $(EXTRALIBS)
libcls_log_la_LDFLAGS = ${AM_LDFLAGS} -version-info 1:0:0 -export-symbols-regex '.*__cls_.*'

noinst_LIBRARIES = libcls_log_client.a

libcls_log_client_a_SOURCES = \
	cls_log_client.cc

noinst_HEADERS = \
	cls_log_types.h \
	cls_log_ops.h \
	cls_log_client.h

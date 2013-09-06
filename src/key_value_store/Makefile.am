include $(top_srcdir)/src/common.mk
include $(top_srcdir)/src/cls/common.mk

radoslib_LTLIBRARIES = libcls_kvs.la

libcls_kvs_la_SOURCES = cls_kvs.cc
libcls_kvs_la_LIBADD = $(PTHREAD_LIBS) $(EXTRALIBS)
libcls_kvs_la_LDFLAGS = ${AM_LDFLAGS} -version-info 1:0:0 -export-symbols-regex '.*__cls_.*'

include $(top_srcdir)/src/common.mk
include $(top_srcdir)/src/cls/common.mk

radoslib_LTLIBRARIES = libcls_rbd.la

libcls_rbd_la_SOURCES = cls_rbd.cc
libcls_rbd_la_LIBADD = $(PTHREAD_LIBS) $(EXTRALIBS)
libcls_rbd_la_LDFLAGS = ${AM_LDFLAGS} -version-info 1:0:0 -export-symbols-regex '.*__cls_.*'

noinst_HEADERS = \
	cls_rbd.h \
	cls_rbd_client.h

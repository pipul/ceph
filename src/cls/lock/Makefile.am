include $(top_srcdir)/src/common.mk
include $(top_srcdir)/src/cls/common.mk

radoslib_LTLIBRARIES = libcls_lock.la

libcls_lock_la_SOURCES = cls_lock.cc
libcls_lock_la_LIBADD = $(PTHREAD_LIBS) $(EXTRALIBS)
libcls_lock_la_LDFLAGS = ${AM_LDFLAGS} -version-info 1:0:0 -export-symbols-regex '.*__cls_.*'

noinst_LIBRARIES = libcls_lock_client.a

libcls_lock_client_a_SOURCES = \
	cls_lock_client.cc \
	cls_lock_types.cc \
	cls_lock_ops.cc

noinst_HEADERS = \
	cls_lock_types.h \
	cls_lock_ops.h \
	cls_lock_client.h

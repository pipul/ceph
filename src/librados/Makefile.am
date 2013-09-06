include $(top_srcdir)/src/common.mk

lib_LTLIBRARIES = librados.la

librados_la_SOURCES = \
	librados.cc \
	RadosClient.cc \
	IoCtxImpl.cc \
	$(top_srcdir)/src/osdc/Objecter.cc \
	$(top_srcdir)/src/osdc/Striper.cc \
	$(top_srcdir)/src/cls/lock/cls_lock_client.cc \
	$(top_srcdir)/src/cls/lock/cls_lock_types.cc \
	$(top_srcdir)/src/cls/lock/cls_lock_ops.cc

librados_la_LIBADD = $(top_builddir)/src/common/libcommon.la $(PTHREAD_LIBS) $(CRYPTO_LIBS) $(EXTRALIBS)
librados_la_LDFLAGS = ${AM_LDFLAGS} -version-info 2:0:0 -export-symbols-regex '^rados_.*'

noinst_HEADERS = \
	snap_set_diff.h \
	AioCompletionImpl.h \
	IoCtxImpl.h \
	PoolAsyncCompletionImpl.h \
	RadosClient.h

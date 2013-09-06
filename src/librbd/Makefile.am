include $(top_srcdir)/src/common.mk

lib_LTLIBRARIES = librbd.la

librbd_la_SOURCES = \
	librbd.cc \
	AioCompletion.cc \
	AioRequest.cc \
	ImageCtx.cc \
	internal.cc \
	LibrbdWriteback.cc \
	WatchCtx.cc \
	$(top_srcdir)/src/osdc/ObjectCacher.cc \
	$(top_srcdir)/src/osdc/Striper.cc \
	$(top_srcdir)/src/librados/snap_set_diff.cc \
	$(top_srcdir)/src/cls/rbd/cls_rbd_client.cc \
	$(top_srcdir)/src/cls/lock/cls_lock_client.cc \
	$(top_srcdir)/src/cls/lock/cls_lock_types.cc \
	$(top_srcdir)/src/cls/lock/cls_lock_ops.cc \
	$(top_srcdir)/src/common/util.cc

librbd_la_LIBADD = $(top_builddir)/src/librados/librados.la
librbd_la_LDFLAGS = ${AM_LDFLAGS} -version-info 1:0:0 \
	-export-symbols-regex '^rbd_.*' $(PTHREAD_LIBS) $(EXTRALIBS)

include $(top_srcdir)/src/common.mk

noinst_LTLIBRARIES = libsystest.la

libsystest_la_SOURCES = \
	cross_process_sem.cc \
	systest_runnable.cc \
	systest_settings.cc \
	cross_process_sem.h \
	st_rados_create_pool.h \
	st_rados_list_objects.h \
	st_rados_delete_objs.h \
	st_rados_delete_pool.h \
	st_rados_notify.h \
	st_rados_watch.h \
	systest_runnable.h \
	systest_settings.h

libsystest_la_LIBADD = $(LIBGLOBAL_LDA)

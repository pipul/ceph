include $(top_srcdir)/src/common.mk

noinst_LTLIBRARIES = libglobal.la

libglobal_la_SOURCES = \
	global_context.cc \
	global_init.cc \
	pidfile.cc \
	signal_handler.cc \
	global_init.h \
	global_context.h \
	signal_handler.h

libglobal_la_LIBADD= $(top_builddir)/src/common/libcommon.la

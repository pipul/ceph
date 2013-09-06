include $(top_srcdir)/src/common.mk

noinst_LTLIBRARIES = libosdc.la

libosdc_la_SOURCES = \
	Objecter.cc \
	ObjectCacher.cc \
	Filer.cc \
	Striper.cc \
	Blinker.h\
	Filer.h\
	Journaler.h\
	ObjectCacher.h\
	Objecter.h\
	Striper.h\
	WritebackHandler.h

libosdc_la_LIBADD = $(top_builddir)/src/common/libcommon.la

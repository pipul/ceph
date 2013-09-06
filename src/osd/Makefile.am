include $(top_srcdir)/src/common.mk

noinst_LTLIBRARIES = libosd.la

libosd_la_SOURCES = \
	PG.cc \
	PGLog.cc \
	ReplicatedPG.cc \
	Ager.cc \
	OSD.cc \
	OSDCap.cc \
	Watch.cc \
	ClassHandler.cc \
	OpRequest.cc \
	SnapMapper.cc \
	Ager.h\
	ClassHandler.h\
	OSD.h\
	OSDCap.h\
	OSDMap.h\
	ObjectVersioner.h\
	OpRequest.h\
	SnapMapper.h\
	PG.h\
	PGLog.h\
	ReplicatedPG.h\
	Watch.h\
	osd_types.h\
	$(top_srcdir)/src/objclass/class_api.cc

libosd_la_LIBADD = \
	$(top_builddir)/src/common/libcommon.la \
	$(top_builddir)/src/os/libos.la

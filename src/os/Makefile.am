include $(top_srcdir)/src/common.mk

noinst_LTLIBRARIES = libos.la

libos_la_SOURCES = \
	FileJournal.cc \
	FileStore.cc \
	chain_xattr.cc \
	ObjectStore.cc \
	JournalingObjectStore.cc \
	LFNIndex.cc \
	HashIndex.cc \
	IndexManager.cc \
	FlatIndex.cc \
	DBObjectMap.cc \
	LevelDBStore.cc \
	WBThrottle.cc \
	BtrfsFileStoreBackend.cc \
	GenericFileStoreBackend.cc \
	ZFSFileStoreBackend.cc \
	btrfs_ioctl.h\
	ZFS.h\
	chain_xattr.h\
	hobject.h \
	CollectionIndex.h\
	FileJournal.h\
	FileStore.h\
	BtrfsFileStoreBackend.h\
	GenericFileStoreBackend.h\
	ZFSFileStoreBackend.h\
	FlatIndex.h\
	HashIndex.h\
	FDCache.h\
	WBThrottle.h\
	IndexManager.h\
	Journal.h\
	JournalingObjectStore.h\
	LFNIndex.h\
	ObjectStore.h\
	SequencerPosition.h \
	ObjectMap.h \
	DBObjectMap.h \
	KeyValueDB.h \
	LevelDBStore.h

libos_la_LIBADD = -lleveldb -lsnappy

if WITH_LIBAIO
libos_la_LIBADD += -laio
endif

if WITH_LIBZFS
noinst_LTLIBRARIES += libos_zfs.la
libos_zfs_la_SOURCES = ZFS.cc
libos_zfs_la_CXXFLAGS = ${AM_CXXFLAGS} ${LIBZFS_CFLAGS}
libos_la_LIBADD += -libos_zfs.la -lzfs
endif

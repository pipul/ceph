include $(top_srcdir)/src/common.mk

noinst_LTLIBRARIES = libclient.la

libclient_la_SOURCES = \
	Client.cc \
	Inode.cc \
	Dentry.cc \
	MetaRequest.cc \
	ClientSnapRealm.cc \
	MetaSession.cc \
	Trace.cc \
	Client.h\
	Dentry.h\
	Dir.h\
	Fh.h\
	Inode.h\
	MetaRequest.h\
	MetaSession.h\
	ClientSnapRealm.h\
	SyntheticClient.h\
	Trace.h\
	fuse_ll.h\
	ioctl.h\
	hadoop/CephFSInterface.h\
	ObjecterWriteback.h

libclient_la_LIBADD = $(top_builddir)/src/osdc/libosdc.la $(LIBEDIT_LIBS)

lib_LTLIBRARIES = libcephfs.la

libcephfs_la_SOURCES = $(top_srcdir)/src/libcephfs.cc
libcephfs_la_LIBADD = libclient.la
libcephfs_la_LDFLAGS =  $(PTHREAD_LIBS) $(CRYPTO_LIBS) $(EXTRALIBS) \
            ${AM_LDFLAGS} -version-info 1:0:0 -export-symbols-regex '^ceph_.*'

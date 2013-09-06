include $(top_srcdir)/src/common.mk

noinst_LTLIBRARIES = libcrc.la libcommon.la

CCAS = ${top_srcdir}/src/yasm-wrapper
AM_CCASFLAGS = -f elf64

libcrc_la_SOURCES = \
	sctp_crc32.c \
	crc32c.cc \
	crc32c_intel_baseline.c \
	crc32c_intel_fast.c

if WITH_GOOD_YASM_ELF64
libcrc_la_SOURCES += crc32c_intel_fast_asm.S
libcrc_la_LIBTOOLFLAGS = --tag=CC
endif

libcommon_la_SOURCES = \
	$(top_srcdir)/src/ceph_ver.c \
	DecayCounter.cc \
	LogClient.cc \
	LogEntry.cc \
	PrebufferedStreambuf.cc \
	BackTrace.cc \
	perf_counters.cc \
	Mutex.cc \
	OutputDataSocket.cc \
	admin_socket.cc \
	admin_socket_client.cc \
	cmdparse.cc \
	escape.c \
	Clock.cc \
	Throttle.cc \
	Timer.cc \
	Finisher.cc \
	environment.cc\
	assert.cc \
	run_cmd.cc \
	WorkQueue.cc \
	ConfUtils.cc \
	MemoryModel.cc \
	armor.c \
	fd.cc \
	xattr.c \
	safe_io.c \
	snap_types.cc \
	str_list.cc \
	ceph_errno.cc \
	RefCountedObj.cc \
	blkdev.cc \
	common_init.cc \
	pipe.c \
	ceph_argparse.cc \
	ceph_context.cc \
	buffer.cc \
	code_environment.cc \
	dout.cc \
	ceph_signal.cc \
	simple_spin.cc \
	Thread.cc \
	Formatter.cc \
	HeartbeatMap.cc \
	config.cc \
	utf8.c \
	mime.c \
	strtol.cc \
	page.cc \
	lockdep.cc \
	version.cc \
	hex.cc \
	entity_name.cc \
	ceph_crypto.cc \
	ceph_crypto_cms.cc \
	ceph_json.cc \
	ipaddr.cc \
	pick_address.cc \
	BackTrace.h\
	RefCountedObj.h\
	HeartbeatMap.h\
	LogClient.h\
	LogEntry.h\
	Preforker.h\
	WorkQueue.h\
	PrioritizedQueue.h\
	ceph_argparse.h\
	ceph_context.h\
	xattr.h\
	blkdev.h\
	compiler_extensions.h\
	debug.h\
	dout.h\
	escape.h\
	fd.h\
	version.h\
	hex.h\
	entity_name.h\
	ceph_errno.h\
	environment.h\
	likely.h\
	lockdep.h\
	obj_bencher.h\
	snap_types.h\
	Clock.h\
	Cond.h\
	ConfUtils.h\
	DecayCounter.h\
	Finisher.h\
	Formatter.h\
	perf_counters.h\
	OutputDataSocket.h \
	admin_socket.h \
	admin_socket_client.h \
	shared_cache.hpp \
	tracked_int_ptr.hpp \
	simple_cache.hpp \
	sharedptr_registry.hpp \
	map_cacher.hpp \
	MemoryModel.h\
	Mutex.h\
	PrebufferedStreambuf.h\
	RWLock.h\
	Semaphore.h\
	SimpleRNG.h\
	TextTable.h\
	Thread.h\
	Throttle.h\
	Timer.h\
	TrackedOp.h\
	arch.h\
	armor.h\
	common_init.h\
	pipe.h\
	code_environment.h \
	ceph_signal.h\
	simple_spin.h\
	run_cmd.h\
	safe_io.h\
	config.h\
	config_obs.h\
	config_opts.h\
	ceph_crypto.h\
	ceph_crypto_cms.h\
	ceph_json.h\
	crc32c_intel_baseline.h\
	crc32c_intel_fast.h\
	lru_map.h\
	utf8.h\
	mime.h\
	pick_address.h\
	sctp_crc32.h\
	secret.h\
	strtol.h\
	static_assert.h\
	AsyncReserver.h\
	sync_filesystem.h \
	cmdparse.h \
	$(top_srcdir)/src/arch/probe.cc \
	$(top_srcdir)/src/arch/intel.c \
	$(top_srcdir)/src/arch/neon.c \
	$(top_srcdir)/src/auth/AuthAuthorizeHandler.cc \
	$(top_srcdir)/src/auth/AuthClientHandler.cc \
	$(top_srcdir)/src/auth/AuthSessionHandler.cc \
	$(top_srcdir)/src/auth/AuthMethodList.cc \
	$(top_srcdir)/src/auth/cephx/CephxAuthorizeHandler.cc \
	$(top_srcdir)/src/auth/cephx/CephxClientHandler.cc \
	$(top_srcdir)/src/auth/cephx/CephxProtocol.cc \
	$(top_srcdir)/src/auth/cephx/CephxSessionHandler.cc \
	$(top_srcdir)/src/auth/none/AuthNoneAuthorizeHandler.cc \
	$(top_srcdir)/src/auth/unknown/AuthUnknownAuthorizeHandler.cc \
	$(top_srcdir)/src/auth/Crypto.cc \
	$(top_srcdir)/src/auth/KeyRing.cc \
	$(top_srcdir)/src/auth/RotatingKeyRing.cc \
	$(top_srcdir)/src/log/Log.cc \
	$(top_srcdir)/src/log/SubsystemMap.cc \
	$(top_srcdir)/src/mon/MonCap.cc \
	$(top_srcdir)/src/mon/MonClient.cc \
	$(top_srcdir)/src/mon/MonMap.cc \
	$(top_srcdir)/src/msg/Accepter.cc \
	$(top_srcdir)/src/msg/DispatchQueue.cc \
	$(top_srcdir)/src/msg/Message.cc \
	$(top_srcdir)/src/msg/Messenger.cc \
	$(top_srcdir)/src/msg/Pipe.cc \
	$(top_srcdir)/src/msg/SimpleMessenger.cc \
	$(top_srcdir)/src/msg/msg_types.cc \
	$(top_srcdir)/src/os/hobject.cc \
	$(top_srcdir)/src/osd/OSDMap.cc \
	$(top_srcdir)/src/osd/osd_types.cc \
	$(top_srcdir)/src/mds/MDSMap.cc \
	$(top_srcdir)/src/mds/inode_backtrace.cc \
	$(top_srcdir)/src/mds/mdstypes.cc \
	$(top_srcdir)/src/include/ceph_fs.cc \
	$(top_srcdir)/src/include/ceph_hash.cc \
	$(top_srcdir)/src/include/ceph_strings.cc \
	$(top_srcdir)/src/include/ceph_frag.cc \
	$(top_srcdir)/src/include/addr_parsing.c

if WITH_PROFILER
libcommon_la_SOURCES += $(top_srcdir)/src/perfglue/cpu_profiler.cc
else
libcommon_la_SOURCES += $(top_srcdir)/src/perfglue/disabled_stubs.cc
endif

libcommon_la_CFLAGS = $(CRYPTO_CFLAGS) $(AM_CFLAGS)
libcommon_la_LIBADD = \
	$(top_builddir)/src/crush/libcrush.la \
	$(top_builddir)/src/json_spirit/libjson_spirit.la \
	libcrc.la -lrt -luuid

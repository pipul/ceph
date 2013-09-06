include $(top_srcdir)/src/common.mk

noinst_LIBRARIES = librgw.a

librgw_a_SOURCES =  \
	librgw.cc \
	rgw_acl.cc \
	rgw_acl_s3.cc \
	rgw_acl_swift.cc \
	rgw_client_io.cc \
	rgw_fcgi.cc \
	rgw_xml.cc \
	rgw_usage.cc \
	rgw_json_enc.cc \
	rgw_user.cc \
	rgw_bucket.cc\
	rgw_tools.cc \
	rgw_rados.cc \
	rgw_http_client.cc \
	rgw_rest_client.cc \
	rgw_rest_conn.cc \
	rgw_op.cc \
	rgw_common.cc \
	rgw_cache.cc \
	rgw_formats.cc \
	rgw_log.cc \
	rgw_multi.cc \
	rgw_policy_s3.cc \
	rgw_gc.cc \
	rgw_multi_del.cc \
	rgw_env.cc \
	rgw_cors.cc \
	rgw_cors_s3.cc \
	rgw_auth_s3.cc \
	rgw_metadata.cc \
	rgw_replica_log.cc \
	rgw_keystone.cc \
	rgw_acl.h\
	rgw_acl_s3.h\
	rgw_acl_swift.h\
	rgw_client_io.h\
	rgw_fcgi.h\
	rgw_xml.h\
	rgw_cache.h\
	rgw_common.h\
	rgw_cors.h\
	rgw_cors_s3.h\
	rgw_cors_swift.h\
	rgw_string.h\
	rgw_formats.h\
	rgw_http_errors.h\
	rgw_log.h\
	rgw_multi.h\
	rgw_policy_s3.h\
	rgw_gc.h\
	rgw_metadata.h\
	rgw_multi_del.h\
	rgw_op.h\
	rgw_http_client.h\
	rgw_swift.h\
	rgw_swift_auth.h\
	rgw_rados.h\
	rgw_replica_log.h \
	rgw_resolve.h\
	rgw_rest.h\
	rgw_rest_swift.h\
	rgw_rest_s3.h\
	rgw_auth_s3.h\
	rgw_rest_admin.h\
	rgw_rest_usage.h\
	rgw_rest_user.h\
	rgw_rest_bucket.h\
	rgw_rest_client.h\
	rgw_rest_conn.h\
	rgw_tools.h\
	rgw_rest_metadata.h\
	rgw_rest_log.h\
	rgw_rest_opstate.h\
	rgw_rest_replica_log.h\
	rgw_rest_config.h\
	rgw_usage.h\
	rgw_user.h\
	rgw_bucket.h\
	rgw_keystone.h

librgw_a_CXXFLAGS = -Woverloaded-virtual ${AM_CXXFLAGS}

EXTRA_DIST = logrotate.conf

$NetBSD$

* On NetBSD %m is only allowed in syslog(3) like functions

--- src/basic/log.h.orig	2022-12-16 10:13:02.000000000 +0000
+++ src/basic/log.h
@@ -103,3 +103,11 @@ void log_assert_failed_return_realm(
 #define log_error_errno(error, ...)     log_full_errno(LOG_ERR,     error, __VA_ARGS__)
 
 #define log_oom() log_oom_internal(LOG_REALM, __FILE__, __LINE__, __func__)
+
+#ifdef __NetBSD__
+#include <string.h>
+#include <errno.h>
+#define LOG_ERR_FMT(fmt, err, ...) fmt ": %s", ##__VA_ARGS__, strerror(-(err))
+#else
+#define LOG_ERR_FMT(fmt, err, ...) fmt ": %m", ##__VA_ARGS__
+#endif

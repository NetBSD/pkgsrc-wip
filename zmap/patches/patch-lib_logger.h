$NetBSD$

Add missing LOG_MAKEPRI

--- lib/logger.h.orig	2026-07-05 07:22:13.630983546 +0000
+++ lib/logger.h
@@ -21,6 +21,10 @@
 #ifndef LOGGER_H
 #define LOGGER_H
 
+#if !defined(LOG_MAKEPRI)
+#define LOG_MAKEPRI(fac, pri) ((fac) | (pri))
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif

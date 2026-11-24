$NetBSD$

* Add support to NetBSD and FreeBSD

--- remote/node_modules/.pnpm/kerberos@2.1.1/node_modules/kerberos/src/kerberos_common.h.orig	2026-11-24 11:16:11.966605383 +0000
+++ remote/node_modules/.pnpm/kerberos@2.1.1/node_modules/kerberos/src/kerberos_common.h
@@ -1,7 +1,7 @@
 #ifndef KERBEROS_COMMON_H
 #define KERBEROS_COMMON_H
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include "unix/kerberos_gss.h"
 
 namespace node_kerberos {

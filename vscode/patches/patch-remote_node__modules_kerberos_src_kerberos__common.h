$NetBSD$

* Add support to NetBSD and FreeBSD

--- remote/node_modules/kerberos/src/kerberos_common.h.orig	2025-03-01 08:55:16.000000000 +0000
+++ remote/node_modules/kerberos/src/kerberos_common.h
@@ -1,7 +1,7 @@
 #ifndef KERBEROS_COMMON_H
 #define KERBEROS_COMMON_H
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include "unix/kerberos_gss.h"
 
 namespace node_kerberos {

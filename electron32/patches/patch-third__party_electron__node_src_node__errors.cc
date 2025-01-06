$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_errors.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_errors.cc
@@ -855,10 +855,6 @@ const char* errno_string(int errorno) {
     ERRNO_CASE(ENOBUFS);
 #endif
 
-#ifdef ENODATA
-    ERRNO_CASE(ENODATA);
-#endif
-
 #ifdef ENODEV
     ERRNO_CASE(ENODEV);
 #endif
@@ -897,14 +893,6 @@ const char* errno_string(int errorno) {
     ERRNO_CASE(ENOSPC);
 #endif
 
-#ifdef ENOSR
-    ERRNO_CASE(ENOSR);
-#endif
-
-#ifdef ENOSTR
-    ERRNO_CASE(ENOSTR);
-#endif
-
 #ifdef ENOSYS
     ERRNO_CASE(ENOSYS);
 #endif
@@ -987,10 +975,6 @@ const char* errno_string(int errorno) {
     ERRNO_CASE(ESTALE);
 #endif
 
-#ifdef ETIME
-    ERRNO_CASE(ETIME);
-#endif
-
 #ifdef ETIMEDOUT
     ERRNO_CASE(ETIMEDOUT);
 #endif

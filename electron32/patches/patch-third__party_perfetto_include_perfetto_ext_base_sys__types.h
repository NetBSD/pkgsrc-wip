$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/perfetto/include/perfetto/ext/base/sys_types.h.orig	2024-10-18 12:40:28.139807500 +0000
+++ third_party/perfetto/include/perfetto/ext/base/sys_types.h
@@ -33,11 +33,7 @@ using uid_t = int;
 using pid_t = int;
 #endif  // !GCC
 
-#if defined(_WIN64)
-using ssize_t = int64_t;
-#else
-using ssize_t = long;
-#endif  // _WIN64
+using ssize_t = intptr_t;
 
 #endif  // OS_WIN
 

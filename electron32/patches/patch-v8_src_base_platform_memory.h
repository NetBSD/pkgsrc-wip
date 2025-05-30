$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/base/platform/memory.h.orig	2024-10-18 12:48:35.124423500 +0000
+++ v8/src/base/platform/memory.h
@@ -19,13 +19,13 @@
 
 #if V8_OS_DARWIN
 #include <malloc/malloc.h>
-#elif V8_OS_ZOS
+#elif (V8_OS_ZOS || V8_OS_BSD)
 #include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
 
-#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS) || V8_OS_WIN
+#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS && !V8_OS_BSD) || V8_OS_WIN
 #define V8_HAS_MALLOC_USABLE_SIZE 1
 #endif
 

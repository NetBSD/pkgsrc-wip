$NetBSD$

* Fallback CLOCK_BOOTTIME to CLOCK_MONOTONIC

--- src/network/nm/utils.cpp.orig	2026-09-19 10:33:01.756119998 +0000
+++ src/network/nm/utils.cpp
@@ -3,6 +3,9 @@
 // We depend on non-std Linux extensions that ctime doesn't put in the global namespace
 // NOLINTNEXTLINE(modernize-deprecated-headers)
 #include <time.h>
+#if !defined(CLOCK_BOOTTIME)
+#define CLOCK_BOOTTIME CLOCK_MONOTONIC
+#endif
 
 #include <qcontainerfwd.h>
 #include <qdatetime.h>

$NetBSD$

# Missing header

--- src/progress.h.orig	2018-04-06 08:17:20 UTC
+++ src/progress.h
@@ -6,7 +6,12 @@
 
 #pragma once
 
-#if defined(__linux__)
+#if defined(__FreeBSD__)
+
+#include <atomic>
+typedef std::atomic<int64>  MCounter;
+
+#elif defined(__linux__)
 
 #if defined(__INTEL_COMPILER_BUILD_DATE) || \
     (defined(__GNUC__) && (__GNUC__ > 4 || \

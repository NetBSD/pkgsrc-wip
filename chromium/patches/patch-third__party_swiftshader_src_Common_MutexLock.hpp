$NetBSD$

--- third_party/swiftshader/src/Common/MutexLock.hpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ third_party/swiftshader/src/Common/MutexLock.hpp
@@ -17,7 +17,7 @@
 
 #include "Thread.hpp"
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 // Use a pthread mutex on Linux. Since many processes may use SwiftShader
 // at the same time it's best to just have the scheduler overhead.
 #include <pthread.h>

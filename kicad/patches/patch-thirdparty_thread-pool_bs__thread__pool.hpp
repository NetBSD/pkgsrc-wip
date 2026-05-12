$NetBSD$

Add NetBSD support.

--- thirdparty/thread-pool/bs_thread_pool.hpp.orig	2026-05-05 12:51:17.719894797 +0000
+++ thirdparty/thread-pool/bs_thread_pool.hpp
@@ -96,7 +96,7 @@ import std;
     #endif
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
     // On Linux, <sys/sysmacros.h> defines macros called `major` and `minor`. We undefine them here so the `version` struct can work.
     #ifdef major
         #undef major

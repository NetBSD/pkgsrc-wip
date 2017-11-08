$NetBSD$

Avoid to (pre)allocate 1GB of memory:

 <https://bugs.webkit.org/show_bug.cgi?id=61137>

From FreeBSD and OpenBSD ports.

--- Source/JavaScriptCore/jit/ExecutableAllocator.cpp.orig	2017-08-09 09:13:42.000000000 +0000
+++ Source/JavaScriptCore/jit/ExecutableAllocator.cpp
@@ -88,7 +88,7 @@ static const size_t fixedExecutableMemor
 static const size_t fixedExecutableMemoryPoolSize = 16 * 1024 * 1024;
 #elif CPU(ARM64)
 static const size_t fixedExecutableMemoryPoolSize = 64 * 1024 * 1024;
-#elif CPU(X86_64)
+#elif CPU(X86_64) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 static const size_t fixedExecutableMemoryPoolSize = 1024 * 1024 * 1024;
 #else
 static const size_t fixedExecutableMemoryPoolSize = 32 * 1024 * 1024;

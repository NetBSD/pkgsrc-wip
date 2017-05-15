$NetBSD$

Avoid to (pre)allocate 1GB of memory:

 <https://bugs.webkit.org/show_bug.cgi?id=61137>

From FreeBSD and OpenBSD ports.

--- Source/JavaScriptCore/jit/ExecutableAllocator.h.orig	Tue Feb 28 09:34:11 2017
+++ Source/JavaScriptCore/jit/ExecutableAllocator.h	Sun Mar 26 13:55:13 2017
@@ -66,7 +66,7 @@ static const size_t fixedExecutableMemoryPoolSize = FI
 static const size_t fixedExecutableMemoryPoolSize = 16 * 1024 * 1024;
 #elif CPU(ARM64)
 static const size_t fixedExecutableMemoryPoolSize = 32 * 1024 * 1024;
-#elif CPU(X86_64)
+#elif CPU(X86_64) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) 
 static const size_t fixedExecutableMemoryPoolSize = 1024 * 1024 * 1024;
 #else
 static const size_t fixedExecutableMemoryPoolSize = 32 * 1024 * 1024;

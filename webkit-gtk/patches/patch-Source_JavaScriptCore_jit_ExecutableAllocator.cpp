$NetBSD: patch-Source_JavaScriptCore_jit_ExecutableAllocator.cpp,v 1.5 2020/09/11 14:47:35 leot Exp $

Avoid to (pre)allocate 1GB of memory on OpenBSD:

 <https://bugs.webkit.org/show_bug.cgi?id=61137>

From OpenBSD ports.

--- Source/JavaScriptCore/jit/ExecutableAllocator.cpp.orig	2022-09-14 11:58:10.356862300 +0000
+++ Source/JavaScriptCore/jit/ExecutableAllocator.cpp
@@ -112,7 +112,7 @@ static constexpr size_t fixedExecutableM
 #else
 static constexpr size_t fixedExecutableMemoryPoolSize = 16 * MB;
 #endif
-#elif CPU(X86_64)
+#elif CPU(X86_64) && !OS(OPENBSD)
 static constexpr size_t fixedExecutableMemoryPoolSize = 1 * GB;
 #else
 static constexpr size_t fixedExecutableMemoryPoolSize = 32 * MB;

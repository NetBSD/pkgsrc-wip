$NetBSD$

--- Source/WTF/wtf/PlatformEnable.h.orig	2024-08-19 06:28:38.539297800 +0000
+++ Source/WTF/wtf/PlatformEnable.h
@@ -694,7 +694,7 @@
 #if !defined(ENABLE_DFG_JIT) && ENABLE(JIT)
 
 /* Enable the DFG JIT on X86 and X86_64. */
-#if CPU(X86_64) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(HURD) || OS(WINDOWS))
+#if CPU(X86_64) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(HURD) || OS(WINDOWS))
 #define ENABLE_DFG_JIT 1
 #endif
 

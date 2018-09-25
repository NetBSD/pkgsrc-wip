$NetBSD$

Add support for NetBSD.

--- Source/WTF/wtf/Platform.h.orig	2018-09-21 19:59:47.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -697,7 +697,7 @@
 #define HAVE_CFNETWORK_STORAGE_PARTITIONING 1
 #endif
 
-#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || defined(__GLIBC__) || defined(__BIONIC__)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS)))
+#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || OS(NETBSD) || defined(__GLIBC__) || defined(__BIONIC__)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS)))
 #define HAVE_MACHINE_CONTEXT 1
 #endif
 
@@ -786,11 +786,11 @@
 
 #if !defined(ENABLE_DFG_JIT) && ENABLE(JIT)
 /* Enable the DFG JIT on X86 and X86_64. */
-#if (CPU(X86) || CPU(X86_64)) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(HURD) || OS(WINDOWS))
+#if (CPU(X86) || CPU(X86_64)) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(HURD) || OS(WINDOWS))
 #define ENABLE_DFG_JIT 1
 #endif
 /* Enable the DFG JIT on ARMv7.  Only tested on iOS, Linux, and FreeBSD. */
-#if (CPU(ARM_THUMB2) || CPU(ARM64)) && (PLATFORM(IOS) || OS(LINUX) || OS(FREEBSD))
+#if (CPU(ARM_THUMB2) || CPU(ARM64)) && (PLATFORM(IOS) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD))
 #define ENABLE_DFG_JIT 1
 #endif
 /* Enable the DFG JIT on ARM. */

$NetBSD: patch-Source_WTF_wtf_PlatformHave.h,v 1.1 2020/03/10 18:14:04 leot Exp $

Add support for NetBSD.

--- Source/WTF/wtf/PlatformHave.h.orig	2020-08-12 09:17:54.000000000 +0000
+++ Source/WTF/wtf/PlatformHave.h
@@ -191,7 +191,7 @@
 #endif
 
 #if OS(DARWIN)
-#define HAVE_AUDIT_TOKEN 1
+//#define HAVE_AUDIT_TOKEN 1
 #endif
 
 #if OS(DARWIN) && __has_include(<mach/mach_exc.defs>) && !PLATFORM(GTK)
@@ -202,7 +202,7 @@
 #define HAVE_HOSTED_CORE_ANIMATION 1
 #endif
 
-#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || defined(__GLIBC__) || defined(__BIONIC__)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS)))
+#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || OS(NETBSD) || defined(__GLIBC__) || defined(__BIONIC__)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS)))
 #define HAVE_MACHINE_CONTEXT 1
 #endif
 

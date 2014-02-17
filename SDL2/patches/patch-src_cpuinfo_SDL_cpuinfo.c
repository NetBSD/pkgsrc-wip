$NetBSD: patch-src_cpuinfo_SDL_cpuinfo.c,v 1.3 2014/02/17 00:08:35 othyro Exp $

Fix building on NetBSD and OpenBSD.

--- src/cpuinfo/SDL_cpuinfo.c.orig	2014-02-07 21:35:46.000000000 +0000
+++ src/cpuinfo/SDL_cpuinfo.c
@@ -653,7 +653,7 @@ SDL_GetSystemRAM(void)
 #endif
 #ifdef HAVE_SYSCTLBYNAME
         if (SDL_SystemRAM <= 0) {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #ifdef HW_REALMEM
             int mib[2] = {CTL_HW, HW_REALMEM};
 #else

$NetBSD: patch-src_cpuinfo_SDL_cpuinfo.c,v 1.4 2014/03/11 03:47:37 othyro Exp $

Fix building on NetBSD and OpenBSD.

--- src/cpuinfo/SDL_cpuinfo.c.orig	2014-03-01 18:07:06.000000000 +0000
+++ src/cpuinfo/SDL_cpuinfo.c
@@ -665,7 +665,7 @@ SDL_GetSystemRAM(void)
 #endif
 #ifdef HAVE_SYSCTLBYNAME
         if (SDL_SystemRAM <= 0) {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #ifdef HW_REALMEM
             int mib[2] = {CTL_HW, HW_REALMEM};
 #else

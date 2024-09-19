$NetBSD: patch-src_compat-api.h,v 1.1 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

Handler args patch from NetBSD xsrc xf86-video-intel-2014

--- src/compat-api.h.orig	2019-03-01 18:22:07.000000000 +0000
+++ src/compat-api.h
@@ -94,11 +94,19 @@
 
 #define SCREEN_INIT_ARGS_DECL ScreenPtr screen, int argc, char **argv
 
+#if (ABI_VIDEODRV_VERSION >= SET_ABI_VERSION(23, 0)) && defined(HANDLER_XSRC_NETBSD)
+#define BLOCKHANDLER_ARGS_DECL ScreenPtr arg, pointer timeout
+#define BLOCKHANDLER_ARGS arg, timeout
+
+#define WAKEUPHANDLER_ARGS_DECL ScreenPtr arg, int result
+#define WAKEUPHANDLER_ARGS arg, result
+#else
 #define BLOCKHANDLER_ARGS_DECL ScreenPtr arg, pointer timeout, pointer read_mask
 #define BLOCKHANDLER_ARGS arg, timeout, read_mask
 
 #define WAKEUPHANDLER_ARGS_DECL ScreenPtr arg, unsigned long result, pointer read_mask
 #define WAKEUPHANDLER_ARGS arg, result, read_mask
+#endif
 
 #define CLOSE_SCREEN_ARGS_DECL ScreenPtr screen
 #define CLOSE_SCREEN_ARGS screen

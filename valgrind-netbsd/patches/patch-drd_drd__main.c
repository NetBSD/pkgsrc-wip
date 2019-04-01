$NetBSD$

--- drd/drd_main.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ drd/drd_main.c
@@ -740,7 +740,7 @@ void drd__atfork_child(ThreadId tid)
 
 static void DRD_(post_clo_init)(void)
 {
-#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
    /* fine */
 #else
    VG_(printf)("\nWARNING: DRD has not yet been tested on this operating system.\n\n");

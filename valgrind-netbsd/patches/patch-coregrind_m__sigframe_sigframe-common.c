$NetBSD$

--- coregrind/m_sigframe/sigframe-common.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_sigframe/sigframe-common.c
@@ -49,7 +49,7 @@ static void track_frame_memory ( Addr ad
    VG_TRACK( new_mem_stack_signal, addr - VG_STACK_REDZONE_SZB, size, tid );
 }
 
-#if defined(VGO_linux) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 /* Extend the stack segment downwards if needed so as to ensure the
    new signal frames are mapped to something.  Return a Bool

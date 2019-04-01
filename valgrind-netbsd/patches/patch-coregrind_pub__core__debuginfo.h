$NetBSD$

--- coregrind/pub_core_debuginfo.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/pub_core_debuginfo.h
@@ -62,7 +62,7 @@ extern void VG_(di_initialise) ( void );
    released by simply re-opening and closing the same file (even via
    different fd!).
 */
-#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 extern ULong VG_(di_notify_mmap)( Addr a, Bool allow_SkFileV, Int use_fd );
 
 extern void VG_(di_notify_munmap)( Addr a, SizeT len );

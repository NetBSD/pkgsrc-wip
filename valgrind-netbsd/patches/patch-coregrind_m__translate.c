$NetBSD$

--- coregrind/m_translate.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_translate.c
@@ -1679,6 +1679,10 @@ Bool VG_(translate) ( ThreadId tid, 
    vex_abiinfo.guest_amd64_assume_gs_is_const = True;
 #  endif
 
+#  if defined(VGP_amd64_netbsd)
+   vex_abiinfo.guest_amd64_assume_fs_is_const = True;
+#  endif
+
 #  if defined(VGP_amd64_darwin)
    vex_abiinfo.guest_amd64_assume_gs_is_const = True;
 #  endif

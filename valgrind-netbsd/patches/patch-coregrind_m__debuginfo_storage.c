$NetBSD$

--- coregrind/m_debuginfo/storage.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_debuginfo/storage.c
@@ -1469,7 +1469,7 @@ Bool preferName ( const DebugInfo* di,
    vlena = VG_(strlen)(a_name);
    vlenb = VG_(strlen)(b_name);
 
-#  if defined(VGO_linux) || defined(VGO_solaris)
+#  if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
 #    define VERSION_CHAR '@'
 #  elif defined(VGO_darwin)
 #    define VERSION_CHAR '$'

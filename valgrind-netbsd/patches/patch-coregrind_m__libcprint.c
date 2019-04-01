$NetBSD$

--- coregrind/m_libcprint.c.orig	2018-07-13 08:52:05.000000000 +0000
+++ coregrind/m_libcprint.c
@@ -1188,7 +1188,7 @@ const HChar *VG_(sr_as_string) ( SysRes 
    return buf;
 }
 
-#elif defined(VGO_darwin) || defined(VGO_solaris)
+#elif defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 const HChar *VG_(sr_as_string) ( SysRes sr )
 {

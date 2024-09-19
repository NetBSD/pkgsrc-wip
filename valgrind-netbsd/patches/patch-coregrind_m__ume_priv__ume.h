$NetBSD$

--- coregrind/m_ume/priv_ume.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_ume/priv_ume.h
@@ -27,7 +27,7 @@
    The GNU General Public License is contained in the file COPYING.
 */
 
-#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 #ifndef __PRIV_UME_H
 #define __PRIV_UME_H
@@ -36,7 +36,7 @@
 
 extern Int VG_(do_exec_inner)(const HChar *exe, ExeInfo *info);
 
-#if defined(VGO_linux) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
 extern Bool VG_(match_ELF) ( const void *hdr, SizeT len );
 extern Int  VG_(load_ELF)  ( Int fd, const HChar *name, ExeInfo *info );
 #elif defined(VGO_darwin)
@@ -52,9 +52,8 @@ extern Int  VG_(load_script)  ( Int fd, 
 
 #endif // __PRIV_UME_H
 
-#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 /*--------------------------------------------------------------------*/
 /*--- end                                                          ---*/
 /*--------------------------------------------------------------------*/
-

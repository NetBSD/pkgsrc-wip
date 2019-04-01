$NetBSD$

--- coregrind/m_debuginfo/priv_readpdb.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_debuginfo/priv_readpdb.h
@@ -32,7 +32,7 @@
    The GNU General Public License is contained in the file COPYING.
 */
 
-#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 #ifndef __PRIV_READPDB_H
 #define __PRIV_READPDB_H
@@ -59,7 +59,7 @@ HChar* ML_(find_name_of_pdb_file)( const
 
 #endif /* ndef __PRIV_READPDB_H */
 
-#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 /*--------------------------------------------------------------------*/
 /*--- end                                                          ---*/

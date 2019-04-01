$NetBSD$

--- coregrind/m_debuginfo/readpdb.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_debuginfo/readpdb.c
@@ -35,7 +35,7 @@
    The GNU General Public License is contained in the file COPYING.
 */
 
-#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 #include "pub_core_basics.h"
 #include "pub_core_debuginfo.h"
@@ -2606,7 +2606,7 @@ HChar* ML_(find_name_of_pdb_file)( const
    return res;
 }
 
-#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 /*--------------------------------------------------------------------*/
 /*--- end                                                          ---*/

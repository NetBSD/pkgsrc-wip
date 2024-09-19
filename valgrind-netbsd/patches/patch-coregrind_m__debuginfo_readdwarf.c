$NetBSD$

--- coregrind/m_debuginfo/readdwarf.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_debuginfo/readdwarf.c
@@ -29,7 +29,7 @@
    The GNU General Public License is contained in the file COPYING.
 */
 
-#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 #include "pub_core_basics.h"
 #include "pub_core_debuginfo.h"
@@ -1692,7 +1692,7 @@ void ML_(read_debuginfo_dwarf1) ( 
 #  define FP_REG         5
 #  define SP_REG         4
 #  define RA_REG_DEFAULT 8
-#elif defined(VGP_amd64_linux) || defined(VGP_amd64_solaris)
+#elif defined(VGP_amd64_linux) || defined(VGP_amd64_solaris) || defined(VGP_amd64_netbsd)
 #  define FP_REG         6
 #  define SP_REG         7
 #  define RA_REG_DEFAULT 16
@@ -4145,7 +4145,7 @@ void ML_(read_callframe_info_dwarf3)
     return;
 }
 
-#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 /*--------------------------------------------------------------------*/
 /*--- end                                                          ---*/

$NetBSD$

--- coregrind/m_debuginfo/readdwarf3.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_debuginfo/readdwarf3.c
@@ -35,7 +35,7 @@
    without prior written permission.
 */
 
-#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 /* REFERENCE (without which this code will not make much sense):
 
@@ -5303,7 +5303,7 @@ ML_(new_dwarf3_reader) (
    TRACE_SYMTAB("\n");
 #endif
 
-#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 /*--------------------------------------------------------------------*/
 /*--- end                                                          ---*/

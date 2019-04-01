$NetBSD$

--- coregrind/m_debuginfo/debuginfo.c.orig	2018-09-30 04:41:00.000000000 +0000
+++ coregrind/m_debuginfo/debuginfo.c
@@ -59,7 +59,7 @@
 #include "priv_tytypes.h"
 #include "priv_storage.h"
 #include "priv_readdwarf.h"
-#if defined(VGO_linux) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
 # include "priv_readelf.h"
 # include "priv_readdwarf3.h"
 # include "priv_readpdb.h"
@@ -816,7 +816,7 @@ void VG_(di_initialise) ( void )
 /*---                                                        ---*/
 /*--------------------------------------------------------------*/
 
-#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 /* Helper (indirect) for di_notify_ACHIEVE_ACCEPT_STATE */
 static Bool overlaps_DebugInfoMappings ( const DebugInfoMapping* map1,
@@ -967,7 +967,7 @@ static ULong di_notify_ACHIEVE_ACCEPT_ST
    truncate_DebugInfoMapping_overlaps( di, di->fsm.maps );
 
    /* And acquire new info. */
-#  if defined(VGO_linux) || defined(VGO_solaris)
+#  if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
    ok = ML_(read_elf_debug_info)( di );
 #  elif defined(VGO_darwin)
    ok = ML_(read_macho_debug_info)( di );
@@ -1249,7 +1249,7 @@ ULong VG_(di_notify_mmap)( Addr a, Bool 
    vg_assert(sr_Res(preadres) > 0 && sr_Res(preadres) <= sizeof(buf1k) );
 
    /* We're only interested in mappings of object files. */
-#  if defined(VGO_linux) || defined(VGO_solaris)
+#  if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
    if (!ML_(is_elf_object_file)( buf1k, (SizeT)sr_Res(preadres), False ))
       return 0;
 #  elif defined(VGO_darwin)
@@ -1698,7 +1698,7 @@ void VG_(di_notify_pdb_debuginfo)( Int f
    if (pdbname) ML_(dinfo_free)(pdbname);
 }
 
-#endif /* defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) */
+#endif /* defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd) */
 
 
 /*------------------------------------------------------------*/
@@ -2295,6 +2295,8 @@ Vg_FnNameKind VG_(get_fnname_kind) ( con
 #      elif defined(VGO_darwin)
        // See readmacho.c for an explanation of this.
        VG_STREQ("start_according_to_valgrind", name) ||  // Darwin, darling
+#      elif defined(VGO_netbsd)
+       VG_STREQ("___start", name) || // main() is called directly from ___start
 #      elif defined(VGO_solaris)
        VG_STREQ("_start", name) || // main() is called directly from _start
 #      else

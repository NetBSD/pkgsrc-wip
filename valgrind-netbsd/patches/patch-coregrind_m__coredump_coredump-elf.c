$NetBSD$

--- coregrind/m_coredump/coredump-elf.c.orig	2018-08-14 07:56:38.000000000 +0000
+++ coregrind/m_coredump/coredump-elf.c
@@ -28,7 +28,7 @@
    The GNU General Public License is contained in the file COPYING.
 */
 
-#if defined(VGO_linux)
+#if defined(VGO_linux) || defined(VGO_netbsd)
 
 #include "pub_core_basics.h"
 #include "pub_core_vki.h"
@@ -66,6 +66,7 @@
 #error VG_WORDSIZE needs to ==4 or ==8
 #endif
 
+#if 0
 /* If true, then this Segment may be mentioned in the core */
 static Bool may_dump(const NSegment *seg)
 {
@@ -740,13 +741,15 @@ void make_elf_coredump(ThreadId tid, con
    VG_(free)(seg_starts);
    VG_(free)(phdrs);
 }
-
+#endif
 void VG_(make_coredump)(ThreadId tid, const vki_siginfo_t *si, ULong max_size)
 {
+#if 0
    make_elf_coredump(tid, si, max_size);
+#endif
 }
 
-#endif // defined(VGO_linux)
+#endif // defined(VGO_linux) || defined(VGO_netbsd)
 
 /*--------------------------------------------------------------------*/
 /*--- end                                                          ---*/

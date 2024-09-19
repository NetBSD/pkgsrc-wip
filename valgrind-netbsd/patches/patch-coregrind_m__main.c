$NetBSD$

--- coregrind/m_main.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_main.c
@@ -1470,7 +1470,7 @@ Int valgrind_main ( Int argc, HChar **ar
    if (!need_help) {
       VG_(debugLog)(1, "main", "Create initial image\n");
 
-#     if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#     if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
       the_iicii.argv              = argv;
       the_iicii.envp              = envp;
       the_iicii.toolname          = VG_(clo_toolname);
@@ -1735,7 +1735,7 @@ Int valgrind_main ( Int argc, HChar **ar
    addr2dihandle = VG_(newXA)( VG_(malloc), "main.vm.2",
                                VG_(free), sizeof(Addr_n_ULong) );
 
-#  if defined(VGO_linux) || defined(VGO_solaris)
+#  if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
    { Addr* seg_starts;
      Int   n_seg_starts;
      Addr_n_ULong anu;
@@ -2401,7 +2401,7 @@ static void final_tidyup(ThreadId tid)
 /*=== Getting to main() alive: LINUX                               ===*/
 /*====================================================================*/
 
-#if defined(VGO_linux)
+#if defined(VGO_linux) || defined(VGO_netbsd)
 
 /* If linking of the final executables is done with glibc present,
    then Valgrind starts at main() above as usual, and all of the
@@ -2566,8 +2566,19 @@ asm("\n"
     "\thlt\n"
     ".previous\n"
 );
-#elif defined(VGP_amd64_linux)
+#elif defined(VGP_amd64_linux) || defined(VGP_amd64_netbsd)
 asm("\n"
+#   if defined(VGP_amd64_netbsd)
+    ".section \".note.netbsd.ident\", \"a\", @note\n"
+    ".long 2f-1f\n"
+    ".long 4f-3f\n"
+    ".long 1\n"
+    "1: .asciz \"NetBSD\"\n"
+    "2: .p2align 2\n"
+    "3: .long 800000001\n" // __NetBSD_Version__
+    "4: .p2align 2\n"
+    "\n"
+#   endif
     ".text\n"
     "\t.globl _start\n"
     "\t.type _start,@function\n"

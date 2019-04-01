$NetBSD$

--- coregrind/m_libcsetjmp.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_libcsetjmp.c
@@ -382,13 +382,13 @@ __asm__(
 /* -------- amd64-{linux,darwin,solaris} -------- */
 
 #if defined(VGP_amd64_linux) || defined(VGP_amd64_darwin) || \
-    defined(VGP_amd64_solaris)
+    defined(VGP_amd64_solaris) || defined(VGP_amd64_netbsd)
 
 __asm__(
 ".text"  "\n"
 ""       "\n"
 
-#if defined(VGP_amd64_linux) || defined(VGP_amd64_solaris)
+#if defined(VGP_amd64_linux) || defined(VGP_amd64_solaris) || defined(VGP_amd64_netbsd)
 ".global VG_MINIMAL_SETJMP"  "\n"  // rdi = jmp_buf
 "VG_MINIMAL_SETJMP:"  "\n"
 
@@ -425,7 +425,7 @@ __asm__(
 ""       "\n"
 
 
-#if defined(VGP_amd64_linux) || defined(VGP_amd64_solaris)
+#if defined(VGP_amd64_linux) || defined(VGP_amd64_solaris) || defined(VGP_amd64_netbsd)
 ".global VG_MINIMAL_LONGJMP"  "\n"
 "VG_MINIMAL_LONGJMP:"  "\n"    // rdi = jmp_buf
 
@@ -473,7 +473,7 @@ __asm__(
 #endif
 );
 
-#endif /* VGP_amd64_linux || VGP_amd64_darwin || VGP_amd64_solaris */
+#endif /* VGP_amd64_linux || VGP_amd64_darwin || VGP_amd64_solaris || VGP_amd64_netbsd */
 
 
 /* -------- x86-{linux,darwin,solaris} -------- */

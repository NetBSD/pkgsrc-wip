$NetBSD$

--- coregrind/pub_core_trampoline.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/pub_core_trampoline.h
@@ -58,6 +58,10 @@
 extern Addr VG_(trampoline_stuff_start);
 extern Addr VG_(trampoline_stuff_end);
 
+#if defined(VGP_amd64_netbsd)
+extern void VG_(amd64_netbsd_SUBST_FOR_sigreturn);
+#endif
+
 #if defined(VGP_x86_linux)
 extern Addr VG_(x86_linux_SUBST_FOR_sigreturn);
 extern Addr VG_(x86_linux_SUBST_FOR_rt_sigreturn);

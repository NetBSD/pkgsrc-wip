$NetBSD$

--- coregrind/m_trampoline.S.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_trampoline.S
@@ -852,7 +852,45 @@ VG_(trampoline_stuff_end):
 #	undef UD2_256
 #	undef UD2_1024
 #	undef UD2_PAGE
+     
+/*---------------- amd64-netbsd ----------------*/
+   
+#else
+#if defined(VGP_amd64_netbsd)
+
+#       define UD2_16     ud2 ; ud2 ; ud2 ; ud2 ;ud2 ; ud2 ; ud2 ; ud2
+#       define UD2_64     UD2_16   ; UD2_16   ; UD2_16   ; UD2_16
+#       define UD2_256    UD2_64   ; UD2_64   ; UD2_64   ; UD2_64
+#       define UD2_1024   UD2_256  ; UD2_256  ; UD2_256  ; UD2_256                                                                                           
+#       define UD2_PAGE   UD2_1024 ; UD2_1024 ; UD2_1024 ; UD2_1024
+
+        /* a leading page of unexecutable code */
+        UD2_PAGE
+
+.global VG_(trampoline_stuff_start)
+VG_(trampoline_stuff_start):
+
+.global VG_(amd64_freebsd_SUBST_FOR_sigreturn)
+VG_(amd64_freebsd_SUBST_FOR_sigreturn):
+        /* This is a very specific sequence which GDB uses to
+           recognize signal handler frames. */   
+        movq    $__NR_fake_sigreturn, %rax
+        movq    %rsp, %rdi
+        addq    $40,%rdi
+        syscall
+        ud2
+.global VG_(trampoline_stuff_end)
+VG_(trampoline_stuff_end):
+           
+        /* and a trailing page of unexecutable code */
+        UD2_PAGE
         
+#       undef UD2_16
+#       undef UD2_64
+#       undef UD2_256                                                                                                                                        
+#       undef UD2_1024
+#       undef UD2_PAGE
+
 /*---------------- x86-darwin ----------------*/
 #else
 #if defined(VGP_x86_darwin)
@@ -1581,6 +1619,7 @@ VG_(trampoline_stuff_end):
 #endif
 #endif
 #endif
+#endif
 
 /* Let the linker know we don't need an executable stack */
 MARK_STACK_NO_EXEC

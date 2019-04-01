$NetBSD$

--- coregrind/m_syscall.c.orig	2018-07-13 08:52:05.000000000 +0000
+++ coregrind/m_syscall.c
@@ -331,6 +331,33 @@ SysRes VG_(mk_SysRes_amd64_solaris) ( Bo
    return res;
 }
 
+#elif defined(VGO_netbsd)
+
+SysRes VG_(mk_SysRes_amd64_netbsd) ( ULong val, ULong val2, Bool err ) {
+   SysRes r;
+   r._isError = err;
+   r._val = val;
+   r._val2 = val2;
+   return r;
+}
+
+/* Generic constructors. */
+SysRes VG_(mk_SysRes_Error) ( UWord err ) {
+   SysRes r;
+   r._val     = err;
+   r._val2    = 0;
+   r._isError = True;
+   return r;
+}
+
+SysRes VG_(mk_SysRes_Success) ( UWord res ) {
+   SysRes r;
+   r._val     = res;
+   r._val2    = 0;
+   r._isError = False;
+   return r;
+}
+
 #else
 #  error "Unknown OS"
 #endif
@@ -676,6 +703,55 @@ asm(
     );
 
 
+#elif defined(VGP_amd64_netbsd)
+extern UWord do_syscall_WRK (
+          UWord syscall_no,    /* %rdi */
+          UWord a1,            /* %rsi */
+          UWord a2,            /* %rdx */
+          UWord a3,            /* %rcx */
+          UWord a4,            /* %r8 */
+          UWord a5,            /* %r9 */
+          UWord a6,            /* 8(%rsp) */
+          UWord a7,            /* 16(%rsp) */
+          UWord a8,            /* 24(%rsp) */
+          UInt *flags,         /* 32(%rsp) */
+          UWord *rv2           /* 40(%rsp) */
+       );
+asm(
+".text\n"
+"do_syscall_WRK:\n"                                                                                                                                          
+        /* Convert function calling convention --> syscall calling
+           convention */
+"      pushq   %rbp\n"
+"      movq    %rsp, %rbp\n"
+"      movq    %rdi, %rax\n"    /* syscall_no */
+"      movq    %rsi, %rdi\n"    /* a1 */
+"      movq    %rdx, %rsi\n"    /* a2 */
+"      movq    %rcx, %rdx\n"    /* a3 */
+"      movq    %r8,  %r10\n"    /* a4 */                                                                                                                     
+"      movq    %r9,  %r8\n"     /* a5 */
+"      movq    16(%rbp), %r9\n"  /* a6 last arg from stack, account for %rbp */
+"      movq    24(%rbp), %r11\n" /* a7 from stack */
+"      pushq  %r11\n"
+"      movq    32(%rbp), %r11\n" /* a8 from stack */
+"      pushq  %r11\n"
+"      subq    $8,%rsp\n"      /* fake return addr */
+"      syscall\n"
+"      jb      1f\n"
+"      movq    48(%rbp),%rsi\n"
+"      movq    %rdx, (%rsi)\n"
+"      movq    %rbp, %rsp\n"
+"      popq    %rbp\n"
+"      ret\n"
+"1:\n"
+"      movq    40(%rbp), %rsi\n"
+"      movl    $1,(%rsi)\n"
+"      movq    %rbp, %rsp\n"                                                                                                                                 
+"      popq    %rbp\n"
+"      ret\n"
+".previous\n"
+);
+
 #elif defined(VGP_amd64_darwin)
 
 /* Incoming args (syscall number + up to 8 args) come in registers and stack
@@ -928,6 +1004,14 @@ SysRes VG_(do_syscall) ( UWord sysno, Re
    UWord val = do_syscall_WRK(sysno,a1,a2,a3,a4,a5,a6);
    return VG_(mk_SysRes_x86_linux)( val );
 
+#  elif defined(VGP_amd64_netbsd)
+   UWord val;
+   UWord val2 = 0;
+   UInt err = 0;
+   val = do_syscall_WRK(sysno, a1, a2, a3, a4, a5,
+                        a6, a7, a8, &err, &val2);
+   return VG_(mk_SysRes_amd64_netbsd)( val, val2, (err & 1) != 0 ? True : False);
+
 #  elif defined(VGP_amd64_linux)
    UWord val = do_syscall_WRK(sysno,a1,a2,a3,a4,a5,a6);
    return VG_(mk_SysRes_amd64_linux)( val );

$NetBSD$

--- lib/tsan/rtl/tsan_rtl_amd64.S.orig	2017-10-17 18:35:43.000000000 +0000
+++ lib/tsan/rtl/tsan_rtl_amd64.S
@@ -170,19 +170,27 @@ ASM_TSAN_SYMBOL(__tsan_report_race_thunk
   CFI_ENDPROC
 
 ASM_HIDDEN(__tsan_setjmp)
-#if !defined(__APPLE__)
+#if defined(__NetBSD__)
+.comm _ZN14__interception15real___setjmp14E,8,8
+#elif !defined(__APPLE__)
 .comm _ZN14__interception11real_setjmpE,8,8
 #endif
+#if defined(__NetBSD__)
+.globl ASM_TSAN_SYMBOL_INTERCEPTOR(__setjmp14)
+ASM_TYPE_FUNCTION(ASM_TSAN_SYMBOL_INTERCEPTOR(__setjmp14))
+ASM_TSAN_SYMBOL_INTERCEPTOR(__setjmp14):
+#else
 .globl ASM_TSAN_SYMBOL_INTERCEPTOR(setjmp)
 ASM_TYPE_FUNCTION(ASM_TSAN_SYMBOL_INTERCEPTOR(setjmp))
 ASM_TSAN_SYMBOL_INTERCEPTOR(setjmp):
+#endif
   CFI_STARTPROC
   // save env parameter
   push %rdi
   CFI_ADJUST_CFA_OFFSET(8)
   CFI_REL_OFFSET(%rdi, 0)
   // obtain %rsp
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   lea 8(%rsp), %rdi
   mov %rdi, %rsi
 #elif defined(__APPLE__)
@@ -204,14 +212,21 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(setjmp):
   CFI_RESTORE(%rdi)
   // tail jump to libc setjmp
   movl $0, %eax
-#if !defined(__APPLE__)
+#if defined(__NetBSD__)
+  movq _ZN14__interception15real___setjmp14E@GOTPCREL(%rip), %rdx
+  jmp *(%rdx)
+#elif !defined(__APPLE__)
   movq _ZN14__interception11real_setjmpE@GOTPCREL(%rip), %rdx
   jmp *(%rdx)
 #else
   jmp ASM_TSAN_SYMBOL(setjmp)
 #endif
   CFI_ENDPROC
+#if defined(__NetBSD__)
+ASM_SIZE(ASM_TSAN_SYMBOL_INTERCEPTOR(__setjmp14))
+#else
 ASM_SIZE(ASM_TSAN_SYMBOL_INTERCEPTOR(setjmp))
+#endif
 
 .comm _ZN14__interception12real__setjmpE,8,8
 .globl ASM_TSAN_SYMBOL_INTERCEPTOR(_setjmp)
@@ -223,7 +238,7 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(_setjmp):
   CFI_ADJUST_CFA_OFFSET(8)
   CFI_REL_OFFSET(%rdi, 0)
   // obtain %rsp
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   lea 8(%rsp), %rdi
   mov %rdi, %rsi
 #elif defined(__APPLE__)
@@ -254,10 +269,17 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(_setjmp):
   CFI_ENDPROC
 ASM_SIZE(ASM_TSAN_SYMBOL_INTERCEPTOR(_setjmp))
 
+#if defined(__NetBSD__)
+.comm _ZN14__interception18real___sigsetjmp14E,8,8
+.globl ASM_TSAN_SYMBOL_INTERCEPTOR(__sigsetjmp14)
+ASM_TYPE_FUNCTION(ASM_TSAN_SYMBOL_INTERCEPTOR(__sigsetjmp14))
+ASM_TSAN_SYMBOL_INTERCEPTOR(__sigsetjmp14):
+#else
 .comm _ZN14__interception14real_sigsetjmpE,8,8
 .globl ASM_TSAN_SYMBOL_INTERCEPTOR(sigsetjmp)
 ASM_TYPE_FUNCTION(ASM_TSAN_SYMBOL_INTERCEPTOR(sigsetjmp))
 ASM_TSAN_SYMBOL_INTERCEPTOR(sigsetjmp):
+#endif
   CFI_STARTPROC
   // save env parameter
   push %rdi
@@ -271,7 +293,7 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(sigsetjmp):
   sub $8, %rsp
   CFI_ADJUST_CFA_OFFSET(8)
   // obtain %rsp
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   lea 24(%rsp), %rdi
   mov %rdi, %rsi
 #elif defined(__APPLE__)
@@ -300,16 +322,23 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(sigsetjmp):
   CFI_RESTORE(%rdi)
   // tail jump to libc sigsetjmp
   movl $0, %eax
-#if !defined(__APPLE__)
+#if defined(__NetBSD__)
+  movq _ZN14__interception18real___sigsetjmp14E@GOTPCREL(%rip), %rdx
+  jmp *(%rdx)
+#elif !defined(__APPLE__)
   movq _ZN14__interception14real_sigsetjmpE@GOTPCREL(%rip), %rdx
   jmp *(%rdx)
 #else
   jmp ASM_TSAN_SYMBOL(sigsetjmp)
 #endif
   CFI_ENDPROC
+#if defined(__NetBSD__)
+ASM_SIZE(ASM_TSAN_SYMBOL_INTERCEPTOR(__sigsetjmp14))
+#else
 ASM_SIZE(ASM_TSAN_SYMBOL_INTERCEPTOR(sigsetjmp))
+#endif
 
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__NetBSD__)
 .comm _ZN14__interception16real___sigsetjmpE,8,8
 .globl ASM_TSAN_SYMBOL_INTERCEPTOR(__sigsetjmp)
 ASM_TYPE_FUNCTION(ASM_TSAN_SYMBOL_INTERCEPTOR(__sigsetjmp))
@@ -355,10 +384,11 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(__sigsetjmp)
   jmp *(%rdx)
   CFI_ENDPROC
 ASM_SIZE(ASM_TSAN_SYMBOL_INTERCEPTOR(__sigsetjmp))
-#endif  // !defined(__APPLE__)
+#endif  // !defined(__APPLE__) && !defined(__NetBSD__)
 
 #if defined(__FreeBSD__) || defined(__linux__)
 /* We do not need executable stack.  */
+/* This note is not needed on NetBSD. */
 .section        .note.GNU-stack,"",@progbits
 #endif
 

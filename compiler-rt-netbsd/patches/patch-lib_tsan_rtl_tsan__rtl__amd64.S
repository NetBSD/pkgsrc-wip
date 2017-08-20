$NetBSD$

--- lib/tsan/rtl/tsan_rtl_amd64.S.orig	2017-07-16 22:40:10.000000000 +0000
+++ lib/tsan/rtl/tsan_rtl_amd64.S
@@ -185,7 +185,7 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(setjmp):
 #if defined(__FreeBSD__)
   lea 8(%rsp), %rdi
   mov %rdi, %rsi
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__NetBSD__)
   lea 16(%rsp), %rdi
   mov %rdi, %rsi
 #elif defined(__linux__)
@@ -226,7 +226,7 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(_setjmp):
 #if defined(__FreeBSD__)
   lea 8(%rsp), %rdi
   mov %rdi, %rsi
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__NetBSD__)
   lea 16(%rsp), %rdi
   mov %rdi, %rsi
 #elif defined(__linux__)
@@ -274,7 +274,7 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(sigsetjmp):
 #if defined(__FreeBSD__)
   lea 24(%rsp), %rdi
   mov %rdi, %rsi
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__NetBSD__)
   lea 32(%rsp), %rdi
   mov %rdi, %rsi
 #elif defined(__linux__)
@@ -327,7 +327,7 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(__sigsetjmp)
   sub $8, %rsp
   CFI_ADJUST_CFA_OFFSET(8)
   // obtain %rsp
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   lea 24(%rsp), %rdi
   mov %rdi, %rsi
 #else

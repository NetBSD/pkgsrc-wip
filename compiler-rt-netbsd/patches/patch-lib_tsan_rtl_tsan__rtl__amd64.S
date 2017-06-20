$NetBSD$

--- lib/tsan/rtl/tsan_rtl_amd64.S.orig	2017-06-03 23:53:57.000000000 +0000
+++ lib/tsan/rtl/tsan_rtl_amd64.S
@@ -178,7 +178,7 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(setjmp):
   CFI_ADJUST_CFA_OFFSET(8)
   CFI_REL_OFFSET(%rdi, 0)
   // obtain %rsp
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   lea 8(%rsp), %rdi
   mov %rdi, %rsi
 #elif defined(__APPLE__)
@@ -219,7 +219,7 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(_setjmp):
   CFI_ADJUST_CFA_OFFSET(8)
   CFI_REL_OFFSET(%rdi, 0)
   // obtain %rsp
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   lea 8(%rsp), %rdi
   mov %rdi, %rsi
 #elif defined(__APPLE__)
@@ -267,7 +267,7 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(sigsetjmp):
   sub $8, %rsp
   CFI_ADJUST_CFA_OFFSET(8)
   // obtain %rsp
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   lea 24(%rsp), %rdi
   mov %rdi, %rsi
 #elif defined(__APPLE__)
@@ -323,7 +323,7 @@ ASM_TSAN_SYMBOL_INTERCEPTOR(__sigsetjmp)
   sub $8, %rsp
   CFI_ADJUST_CFA_OFFSET(8)
   // obtain %rsp
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   lea 24(%rsp), %rdi
   mov %rdi, %rsi
 #else

$NetBSD$

--- src/VBox/VMM/testcase/tstX86-1.cpp.orig	2016-03-04 19:30:15.000000000 +0000
+++ src/VBox/VMM/testcase/tstX86-1.cpp
@@ -112,6 +112,13 @@ static void sigHandler(int iSig, siginfo
     uintptr_t   uErr    = ~(uintptr_t)0;
     uintptr_t   uCr2    = ~(uintptr_t)0;
 
+# elif defined(RT_ARCH_AMD64) && defined(RT_OS_NETBSD)
+    uintptr_t  *puPC    = (uintptr_t *)&pCtx->pc;
+    uintptr_t  *puSP    = (uintptr_t *)&pCtx->sp;
+    uintptr_t   uTrapNo = ~(uintptr_t)0;
+    uintptr_t   uErr    = ~(uintptr_t)0;
+    uintptr_t   uCr2    = ~(uintptr_t)0;
+
 # elif defined(RT_ARCH_AMD64)
     uintptr_t  *puPC    = (uintptr_t *)&pCtx->uc_mcontext.gregs[REG_RIP];
     uintptr_t  *puSP    = (uintptr_t *)&pCtx->uc_mcontext.gregs[REG_RSP];
@@ -267,4 +274,3 @@ int main()
 
     return RTTestSummaryAndDestroy(hTest);
 }
-

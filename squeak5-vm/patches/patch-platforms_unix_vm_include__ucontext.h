$NetBSD$

--- platforms/unix/vm/include_ucontext.h.orig	2022-06-02 14:10:44.000000000 +0000
+++ platforms/unix/vm/include_ucontext.h
@@ -93,6 +93,10 @@
 # define _PC_IN_UCONTEXT uc_mcontext.mc_rip
 # define _FP_IN_UCONTEXT uc_mcontext.mc_rbp
 # define _SP_IN_UCONTEXT uc_mcontext.mc_rsp
+#elif __NetBSD__ && __amd64__
+# define _PC_IN_UCONTEXT uc_mcontext.__gregs[_REG_RIP]
+# define _FP_IN_UCONTEXT uc_mcontext.__gregs[_REG_RBP]
+# define _SP_IN_UCONTEXT uc_mcontext.__gregs[_REG_RSP]
 #elif __OpenBSD__ && __i386__
 # define _PC_IN_UCONTEXT sc_eip
 # define _FP_IN_UCONTEXT sc_ebp

$NetBSD$

--- platforms/unix/vm/include_ucontext.h.orig	2018-10-19 04:12:21.000000000 +0000
+++ platforms/unix/vm/include_ucontext.h
@@ -46,6 +46,8 @@
 # define _PC_IN_UCONTEXT uc_mcontext.mc_eip
 #elif __FreeBSD__ && __amd64__
 # define _PC_IN_UCONTEXT uc_mcontext.mc_rip
+#elif __NetBSD__ && __amd64__
+# define _PC_IN_UCONTEXT uc_mcontext.__gregs[_REG_RIP]
 #elif __OpenBSD__ && __i386__
 # define _PC_IN_UCONTEXT sc_eip
 #elif __OpenBSD__ && __amd64__

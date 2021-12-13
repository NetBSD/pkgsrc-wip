$NetBSD$

--- libraries/source/nvtt/src/src/nvcore/Debug.cpp.orig	2015-07-21 15:53:21.000000000 +0000
+++ libraries/source/nvtt/src/src/nvcore/Debug.cpp
@@ -213,6 +213,14 @@ namespace 
 			ucontext_t * ucp = (ucontext_t *)secret;
 			return (void *)ucp->uc_mcontext.mc_eip;
 #		endif
+#	elif NV_OS_NETBSD
+#		if NV_CPU_X86_64
+			ucontext_t * ucp = (ucontext_t *)secret;
+			return (void *)ucp->uc_mcontext.__gregs[_REG_RIP];
+#		elif NV_CPU_X86
+			ucontext_t * ucp = (ucontext_t *)secret;
+			return (void *)ucp->uc_mcontext.__gregs[_REG_EIP];
+#		endif
 #	elif NV_OS_OPENBSD
 #		if NV_CPU_X86_64
 			ucontext_t * ucp = (ucontext_t *)secret;
@@ -559,4 +567,3 @@ void debug::disableSigHandler()
 	
 #endif
 }
-

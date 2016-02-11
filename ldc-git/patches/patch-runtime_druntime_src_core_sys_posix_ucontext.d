$NetBSD$

--- runtime/druntime/src/core/sys/posix/ucontext.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/ucontext.d
@@ -701,6 +701,37 @@ else version( FreeBSD )
         int[4]          __spare__;
     }
 }
+else version( NetBSD )
+{
+    alias __ucontext ucontext_t;
+
+    struct __ucontext {
+	uint	uc_flags;	/* properties */
+	ucontext_t* 	uc_link;	/* context to resume */
+	sigset_t	uc_sigmask;	/* signals blocked in this context */
+	stack_t		uc_stack;	/* the stack used by this context */
+	mcontext_t	uc_mcontext;	/* machine state */
+//#if defined(_UC_MACHINE_PAD)
+//	long		__uc_pad[_UC_MACHINE_PAD];
+    }
+
+    version( X86_64 )
+    {
+        enum _NGREG = 26;
+	alias c_ulong  __greg_t;
+        alias __greg_t[_NGREG] __gregset_t;
+        alias char[512] __fpregset_t; //__aligned(8);
+
+        struct mcontext_t {
+      	    __gregset_t	__gregs;
+	    __greg_t	_mc_tlsbase;
+	    __fpregset_t	__fpregs;
+        }
+    }
+    else
+      static assert(false, "Unsupported architecture");
+
+}
 else version ( Solaris )
 {
     alias uint[4] upad128_t;

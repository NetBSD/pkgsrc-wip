$NetBSD$

--- runtime/druntime/src/core/sys/posix/ucontext.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/ucontext.d
@@ -766,6 +766,62 @@ else version( DragonFlyBSD )
         int[4]          __spare__;
     }
 }
+else version( NetBSD )
+{
+
+    version( X86_64 )
+    {
+      enum { NGREG = 26 };
+      alias __greg_t = ulong;
+      alias __gregset_t = __greg_t[NGREG];
+      alias __fpregset_t = align(8)ubyte[512];
+
+      struct mcontext_t {
+        __gregset_t     __gregs;
+        __greg_t        _mc_tlsbase;
+        __fpregset_t    __fpregs;
+      }
+    }
+    else version( X86 )
+    {
+      enum { NGREG = 19 };
+      alias __greg_t = ulong;
+      alias __gregset_t = __greg_t[_NGREG];
+      struct __fpregset_t{
+        union __fp_reg_set{
+                struct __fpchip_state{
+                        int[27]     __fp_state; /* Environment and registers */
+                } ;       /* x87 regs in fsave format */
+                struct __fp_xmm_state{
+                        ubyte[512]    __fp_xmm;
+                } ;       /* x87 and xmm regs in fxsave format */
+                int[128]     __fp_fpregs;
+        };
+        __fpregset_t __fp_reg_set;
+        int[33]     __fp_pad;                   /* Historic padding */
+      };
+
+      struct mcontext_t {
+        __gregset_t     __gregs;
+        __fpregset_t    __fpregs;
+        __greg_t        _mc_tlsbase;
+      }
+    }
+
+    struct ucontext_t
+    {
+        uint    uc_flags;       /* properties */
+        ucontext_t *    uc_link;        /* context to resume */
+        sigset_t        uc_sigmask;     /* signals blocked in this context */
+        stack_t         uc_stack;       /* the stack used by this context */
+        mcontext_t      uc_mcontext;    /* machine state */
+        /+ todo #if defined(_UC_MACHINE_PAD)
+                long            __uc_pad[_UC_MACHINE_PAD];
+        #endif
+        +/
+
+    }
+}
 else version ( Solaris )
 {
     alias uint[4] upad128_t;

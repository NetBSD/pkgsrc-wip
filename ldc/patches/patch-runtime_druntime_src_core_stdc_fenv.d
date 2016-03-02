$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/stdc/fenv.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/stdc/fenv.d
@@ -190,6 +190,46 @@ else version ( FreeBSD )
 
     alias ushort fexcept_t;
 }
+else version ( NetBSD )
+{
+    version(X86_64)
+    {
+        struct fenv_t
+        {
+            struct _x87
+            {
+                    uint control;       /* Control word register */
+                    uint status;        /* Status word register */
+                    uint tag;           /* Tag word register */
+                    uint[4] others;     /* EIP, Pointer Selector, etc */
+            };
+            _x87 x87;
+
+            uint mxcsr;                 /* Control and status register */
+        }
+   }
+   version(X86)
+   {
+        struct fenv_t
+        {
+            struct _x87
+            {
+                    ushort control;       /* Control word register */
+                    ushort unused1;
+                    ushort status;        /* Status word register */
+                    ushort unused2;
+                    ushort tag;           /* Tag word register */
+                    ushort unused3;
+                    uint[4] others;     /* EIP, Pointer Selector, etc */
+            };
+            _x87 x87;
+            uint32_t mxcsr;                 /* Control and status register */
+        };
+
+    }
+
+    alias uint fexcept_t;
+}
 else version( CRuntime_Bionic )
 {
     version(X86)
@@ -304,6 +344,12 @@ else version( FreeBSD )
     ///
     enum FE_DFL_ENV = &__fe_dfl_env;
 }
+else version( NetBSD )
+{
+    private extern const fenv_t __fe_dfl_env;
+    ///
+    enum FE_DFL_ENV = &__fe_dfl_env;
+}
 else version( CRuntime_Bionic )
 {
     private extern const fenv_t __fe_dfl_env;

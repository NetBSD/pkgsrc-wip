$NetBSD$

--- runtime/druntime/src/core/stdc/fenv.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/stdc/fenv.d
@@ -190,6 +190,28 @@ else version ( FreeBSD )
 
     alias ushort fexcept_t;
 }
+else version( NetBSD )
+{
+    version( X86_64 )
+    {
+        struct fenv_t {
+ 	    struct x87_t {
+ 	        uint    control;	/* Control word register */
+  	        uint    status;	        /* Status word register */
+	        uint    tag;  	        /* Tag word register */
+	        uint[4] others;	        /* EIP, Pointer Selector, etc */
+ 	    }
+	    x87_t x87;
+ 
+            uint mxcsr;			/* Control and status register */
+        }
+	alias uint fexcept_t;
+    }
+    else
+    {
+        static assert(false, "Architecture not supported.");
+    }
+}
 else version( CRuntime_Bionic )
 {
     version(X86)
@@ -304,6 +326,11 @@ else version( FreeBSD )
     ///
     enum FE_DFL_ENV = &__fe_dfl_env;
 }
+else version( NetBSD )
+{
+    extern const fenv_t		__fe_dfl_env;
+    enum FE_DFL_ENV = &__fe_dfl_env;
+}
 else version( CRuntime_Bionic )
 {
     private extern const fenv_t __fe_dfl_env;

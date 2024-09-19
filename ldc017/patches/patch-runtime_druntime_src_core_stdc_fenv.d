$NetBSD$

--- runtime/druntime/src/core/stdc/fenv.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/stdc/fenv.d
@@ -338,6 +338,12 @@ else version( DragonFlyBSD )
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

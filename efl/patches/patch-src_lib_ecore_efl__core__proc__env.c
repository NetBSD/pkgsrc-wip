$NetBSD$

* Add NetBSD support

--- src/lib/ecore/efl_core_proc_env.c.orig	2023-12-23 15:56:36.000000000 +0000
+++ src/lib/ecore/efl_core_proc_env.c
@@ -13,7 +13,7 @@
 
 #define MY_CLASS EFL_CORE_PROC_ENV_CLASS
 
-#if defined (__FreeBSD__) || defined (__OpenBSD__)
+#if defined (__FreeBSD__) || defined (__OpenBSD__) || defined(__NetBSD__)
 # include <dlfcn.h>
 static char ***_dl_environ;
 #elif !defined(_MSC_VER)
@@ -42,7 +42,7 @@ _sync(Efl_Core_Env *obj, Efl_Core_Proc_E
         existing_keys = eina_list_append(existing_keys, key);
      }
 
-#if defined (__FreeBSD__) || defined (__OpenBSD__)
+#if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
    _dl_environ = dlsym(NULL, "environ");
    if (_dl_environ) loc_env = *_dl_environ;
    else ERR("Can't find envrion symbol");
@@ -121,7 +121,7 @@ _efl_core_proc_env_efl_core_env_clear(Eo
 #ifdef HAVE_CLEARENV
         clearenv();
 #else
-# if defined (__FreeBSD__) || defined (__OpenBSD__)
+# if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
         _dl_environ = dlsym(NULL, "environ");
         if (_dl_environ) *_dl_environ = NULL;
         else ERR("Can't find envrion symbol");

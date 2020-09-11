$NetBSD$

* Add NetBSD support

--- src/lib/ecore/ecore_exe_posix.c.orig	2020-09-22 17:54:50.000000000 +0000
+++ src/lib/ecore/ecore_exe_posix.c
@@ -218,7 +218,7 @@ _impl_ecore_exe_run_priority_get(void)
    return run_pri;
 }
 
-#if defined (__FreeBSD__) || defined (__OpenBSD__)
+#if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (NetBSD)
 # include <dlfcn.h>
 static char ***_dl_environ;
 #else
@@ -350,7 +350,7 @@ _impl_ecore_exe_efl_object_finalize(Eo *
 #ifdef HAVE_SYSTEMD
          char **env = NULL, **e;
 
-# if defined (__FreeBSD__) || defined (__OpenBSD__)
+# if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (NetBSD)
          _dl_environ = dlsym(NULL, "environ");
          env = *_dl_environ;
 # else

$NetBSD$

* Add NetBSD support

--- src/lib/ecore/efl_exe.c.orig	2020-05-11 11:32:41.000000000 +0000
+++ src/lib/ecore/efl_exe.c
@@ -32,7 +32,7 @@
 #  include <sys/wait.h>
 # endif
 # ifndef HAVE_CLEARENV
-#  if defined (__FreeBSD__) || defined (__OpenBSD__)
+#  if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
 #   include <dlfcn.h>
 static char ***_dl_environ;
 #  else
@@ -531,7 +531,7 @@ _efl_exe_efl_task_run(Eo *obj, Efl_Exe_D
 # ifdef HAVE_CLEARENV
         clearenv();
 # else
-#  if defined (__FreeBSD__) || defined (__OpenBSD__)
+#  if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
         _dl_environ = dlsym(NULL, "environ");
         if (_dl_environ) *_dl_environ = NULL;
         else ERR("Can't find envrion symbol");

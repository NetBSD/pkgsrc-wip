$NetBSD$

* Add NetBSD support

--- src/lib/ecore/efl_exe.c.orig	2020-09-22 17:54:50.000000000 +0000
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
@@ -577,7 +577,7 @@ _efl_exe_efl_task_run(Eo *obj, Efl_Exe_D
 
    // clear systemd notify socket... only relevant for systemd world,
    // otherwise shouldn't be trouble
-# if defined (__FreeBSD__) || defined (__OpenBSD__)
+# if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
    _dl_environ = dlsym(NULL, "environ");
    if (_dl_environ) env = *_dl_environ;
 # else
@@ -620,7 +620,7 @@ _efl_exe_efl_task_run(Eo *obj, Efl_Exe_D
           }
         // yes - we dont free itr or itr2 - we're going to exec below or exit
         // also put newenv array on stack pointign to the strings in the env
-# if defined (__FreeBSD__) || defined (__OpenBSD__)
+# if defined (__FreeBSD__) || defined (__OpenBSD__) || (__NetBSD__)
         if (_dl_environ) *_dl_environ = newenv;
         else ERR("Can't find envrion symbol");
 # else

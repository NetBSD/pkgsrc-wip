$NetBSD$

Adapt pthread_setname_np calling convention for NetBSD.
http://debbugs.gnu.org/cgi/bugreport.cgi?bug=39363

--- src/systhread.c.orig	2020-01-30 22:42:52.049505198 +0000
+++ src/systhread.c
@@ -217,7 +217,11 @@ sys_thread_set_name (const char *name)
  #ifdef HAVE_PTHREAD_SETNAME_NP_1ARG
   pthread_setname_np (p_name);
  #else
+  #ifdef __NetBSD__
+  pthread_setname_np (pthread_self (), "%s", p_name);
+  #else
   pthread_setname_np (pthread_self (), p_name);
+  #endif
  #endif
 #endif
 }

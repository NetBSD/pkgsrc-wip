$NetBSD$

Adapt pthread_setname_np calling convention for NetBSD.
http://debbugs.gnu.org/cgi/bugreport.cgi?bug=39363

--- src/systhread.c.orig	2020-01-31 17:00:50.894938840 +0000
+++ src/systhread.c
@@ -214,11 +214,13 @@ sys_thread_set_name (const char *name)
   char p_name[TASK_COMM_LEN];
   strncpy (p_name, name, TASK_COMM_LEN - 1);
   p_name[TASK_COMM_LEN - 1] = '\0';
- #ifdef HAVE_PTHREAD_SETNAME_NP_1ARG
+# ifdef HAVE_PTHREAD_SETNAME_NP_1ARG
   pthread_setname_np (p_name);
- #else
+# elif defined HAVE_PTHREAD_SETNAME_NP_3ARG
+  pthread_setname_np (pthread_self (), "%s", p_name);
+# else
   pthread_setname_np (pthread_self (), p_name);
- #endif
+# endif
 #endif
 }
 

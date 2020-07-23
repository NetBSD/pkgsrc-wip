$NetBSD$

Clear the user process environment for systems that do not provide clearenv().

--- src/process.c.orig	2018-09-05 01:33:31.000000000 +0000
+++ src/process.c
@@ -73,6 +73,8 @@ static GHashTable *processes = NULL;
 static pid_t signal_pid;
 static int signal_pipe[2];
 
+extern char **environ;
+
 Process *
 process_get_current (void)
 {
@@ -241,7 +243,7 @@ process_start (Process *process, gboolea
 #ifdef HAVE_CLEARENV
             clearenv ();
 #else
-            environ = NULL;
+            *environ = NULL;
 #endif
         for (guint i = 0; i < env_length; i++)
             setenv (env_keys[i], env_values[i], TRUE);

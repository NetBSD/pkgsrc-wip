$NetBSD: patch-src_polkitagent_polkitagentsession.c,v 1.1 2015/01/07 05:38:31 obache Exp $

PolkitAgentSession: fix race between child and io watches

--- src/polkitagent/polkitagentsession.c.orig	2013-04-29 17:28:57.000000000 +0000
+++ src/polkitagent/polkitagentsession.c
@@ -92,7 +92,6 @@ struct _PolkitAgentSession
   int child_stdout;
   GPid child_pid;
 
-  GSource *child_watch_source;
   GSource *child_stdout_watch_source;
   GIOChannel *child_stdout_channel;
 
@@ -377,13 +376,6 @@ kill_helper (PolkitAgentSession *session
       session->child_pid = 0;
     }
 
-  if (session->child_watch_source != NULL)
-    {
-      g_source_destroy (session->child_watch_source);
-      g_source_unref (session->child_watch_source);
-      session->child_watch_source = NULL;
-    }
-
   if (session->child_stdout_watch_source != NULL)
     {
       g_source_destroy (session->child_stdout_watch_source);
@@ -429,26 +421,6 @@ complete_session (PolkitAgentSession *se
     }
 }
 
-static void
-child_watch_func (GPid     pid,
-                  gint     status,
-                  gpointer user_data)
-{
-  PolkitAgentSession *session = POLKIT_AGENT_SESSION (user_data);
-
-  if (G_UNLIKELY (_show_debug ()))
-    {
-      g_print ("PolkitAgentSession: in child_watch_func for pid %d (WIFEXITED=%d WEXITSTATUS=%d)\n",
-               (gint) pid,
-               WIFEXITED(status),
-               WEXITSTATUS(status));
-    }
-
-  /* kill all the watches we have set up, except for the child since it has exited already */
-  session->child_pid = 0;
-  complete_session (session, FALSE);
-}
-
 static gboolean
 io_watch_have_data (GIOChannel    *channel,
                     GIOCondition   condition,
@@ -475,10 +447,13 @@ io_watch_have_data (GIOChannel    *chann
                           NULL,
                           NULL,
                           &error);
-  if (error != NULL)
+  if (error != NULL || line == NULL)
     {
-      g_warning ("Error reading line from helper: %s", error->message);
-      g_error_free (error);
+      /* In case we get just G_IO_HUP, line is NULL but error is
+         unset.*/
+      g_warning ("Error reading line from helper: %s",
+                 error ? error->message : "nothing to read");
+      g_clear_error (error);
 
       complete_session (session, FALSE);
       goto out;
@@ -540,6 +515,9 @@ io_watch_have_data (GIOChannel    *chann
   g_free (line);
   g_free (unescaped);
 
+  if (condition & (G_IO_ERR | G_IO_HUP))
+    complete_session (session, FALSE);
+
   /* keep the IOChannel around */
   return TRUE;
 }
@@ -650,12 +628,9 @@ polkit_agent_session_initiate (PolkitAge
   if (G_UNLIKELY (_show_debug ()))
     g_print ("PolkitAgentSession: spawned helper with pid %d\n", (gint) session->child_pid);
 
-  session->child_watch_source = g_child_watch_source_new (session->child_pid);
-  g_source_set_callback (session->child_watch_source, (GSourceFunc) child_watch_func, session, NULL);
-  g_source_attach (session->child_watch_source, g_main_context_get_thread_default ());
-
   session->child_stdout_channel = g_io_channel_unix_new (session->child_stdout);
-  session->child_stdout_watch_source = g_io_create_watch (session->child_stdout_channel, G_IO_IN);
+  session->child_stdout_watch_source = g_io_create_watch (session->child_stdout_channel,
+                                                          G_IO_IN | G_IO_ERR | G_IO_HUP);
   g_source_set_callback (session->child_stdout_watch_source, (GSourceFunc) io_watch_have_data, session, NULL);
   g_source_attach (session->child_stdout_watch_source, g_main_context_get_thread_default ());
 

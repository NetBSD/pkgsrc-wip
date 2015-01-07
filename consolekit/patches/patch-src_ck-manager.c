$NetBSD: patch-src_ck-manager.c,v 1.1 2015/01/07 04:46:57 obache Exp $

XXX revert 4f88228f31a63c026c424a92827f26ad7535275c
The Kit people assume the world runs Linux and PAM, see
https://bugs.freedesktop.org/show_bug.cgi?id=28377

Fix deprecated use of polkit_authority_get().

--- src/ck-manager.c.orig	2010-10-26 14:34:03.000000000 +0000
+++ src/ck-manager.c
@@ -1659,6 +1659,7 @@ open_session_for_leader (CkManager      
         dbus_g_method_return (context, cookie);
 }
 
+#ifdef __linux__
 enum {
         PROP_STRING,
         PROP_BOOLEAN,
@@ -1799,6 +1800,7 @@ add_param_boolean (GPtrArray  *parameter
 
         g_ptr_array_add (parameters, g_value_get_boxed (&param_val));
 }
+#endif /* __linux__ */
 
 static void
 verify_and_open_session_for_leader (CkManager             *manager,
@@ -1806,6 +1808,7 @@ verify_and_open_session_for_leader (CkMa
                                     GPtrArray             *parameters,
                                     DBusGMethodInvocation *context)
 {
+#ifdef __linux__
         /* Only allow a local session if originating from an existing
            local session.  Effectively this means that only trusted
            parties can create local sessions. */
@@ -1827,6 +1830,7 @@ verify_and_open_session_for_leader (CkMa
 
                 add_param_boolean (parameters, "is-local", is_local);
         }
+#endif /* __linux__ */
 
         open_session_for_leader (manager,
                                  leader,
@@ -2423,7 +2427,14 @@ register_manager (CkManager *manager)
         GError *error = NULL;
 
 #ifdef HAVE_POLKIT
-        manager->priv->pol_ctx = polkit_authority_get ();
+        manager->priv->pol_ctx = polkit_authority_get_sync (NULL, &error);
+        if (manager->priv->pol_ctx == NULL) {
+                if (error != NULL) {
+                        g_critical ("error getting polkit authority: %s", error->message);
+                        g_error_free (error);
+                }
+                exit (1);
+        }
 #endif
 
         error = NULL;

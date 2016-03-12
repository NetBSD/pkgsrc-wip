$NetBSD: patch-src_polkitbackend_polkitbackendjsauthority.c,v 1.3 2015/04/02 14:55:36 bsiegert Exp $

* for *BSD netgroup functions
* for no SIGPOLL
* Fix a memory leak

--- src/polkitbackend/polkitbackendjsauthority.c.orig	2015-06-19 20:39:58.000000000 +0000
+++ src/polkitbackend/polkitbackendjsauthority.c
@@ -24,7 +24,12 @@
 #include <errno.h>
 #include <pwd.h>
 #include <grp.h>
+#if defined(__NetBSD__)
+#include <netgroup.h>
+#define BSD_NETENT
+#else
 #include <netdb.h>
+#endif
 #include <string.h>
 #include <glib/gstdio.h>
 #include <locale.h>
@@ -812,7 +817,7 @@ subject_to_jsval (PolkitBackendJsAuthori
   if (passwd == NULL)
     {
       user_name = g_strdup_printf ("%d", (gint) uid);
-      g_warning ("Error looking up info for uid %d: %m", (gint) uid);
+      g_warning ("Error looking up info for uid %d: %s", (gint) uid, g_strerror(errno));
     }
   else
     {
@@ -826,7 +831,7 @@ subject_to_jsval (PolkitBackendJsAuthori
                         gids,
                         &num_gids) < 0)
         {
-          g_warning ("Error looking up groups for uid %d: %m", (gint) uid);
+          g_warning ("Error looking up groups for uid %d: %s", (gint) uid, g_strerror(errno));
         }
       else
         {
@@ -1508,8 +1513,13 @@ js_polkit_user_is_in_netgroup (JSContext
   JSBool ret = JS_FALSE;
   JSString *user_str;
   JSString *netgroup_str;
+#ifdef BSD_NETENT
+  const char *user;
+  const char *netgroup;
+#else
   char *user;
   char *netgroup;
+#endif
   JSBool is_in_netgroup = JS_FALSE;
 
   if (!JS_ConvertArguments (cx, argc, JS_ARGV (cx, vp), "SS", &user_str, &netgroup_str))

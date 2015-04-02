$NetBSD: patch-src_polkitbackend_polkitbackendjsauthority.c,v 1.3 2015/04/02 14:55:36 bsiegert Exp $

* for *BSD netgroup functions
* for no SIGPOLL
* Fix a memory leak

--- src/polkitbackend/polkitbackendjsauthority.c.orig	2013-05-06 18:28:21.000000000 +0000
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
@@ -1286,7 +1291,9 @@ get_signal_name (gint signal_number)
     _HANDLE_SIG (SIGTTIN);
     _HANDLE_SIG (SIGTTOU);
     _HANDLE_SIG (SIGBUS);
+#ifdef SIGPOLL
     _HANDLE_SIG (SIGPOLL);
+#endif
     _HANDLE_SIG (SIGPROF);
     _HANDLE_SIG (SIGSYS);
     _HANDLE_SIG (SIGTRAP);
@@ -1363,7 +1370,6 @@ js_polkit_spawn (JSContext  *cx,
           goto out;
 	}
       s = JS_EncodeString (cx, JSVAL_TO_STRING (elem_val));
-      s = JS_EncodeString (cx, JSVAL_TO_STRING (elem_val));
       argv[n] = g_strdup (s);
       JS_free (cx, s);
     }
@@ -1450,8 +1456,13 @@ js_polkit_user_is_in_netgroup (JSContext
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

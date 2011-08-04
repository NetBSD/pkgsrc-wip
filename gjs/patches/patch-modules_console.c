$NetBSD: patch-modules_console.c,v 1.1.1.1 2011/08/04 15:41:03 ryo-on Exp $

* JSScript and JS_DestroyScript is obsolete.

--- modules/console.c.orig	2011-04-01 18:49:49.000000000 +0000
+++ modules/console.c
@@ -161,7 +161,7 @@ gjs_console_interact(JSContext *context,
 {
     JSObject *object = JS_THIS_OBJECT(context, vp);
     gboolean eof = FALSE;
-    JSScript *script = NULL;
+    JSObject *script = NULL;
     jsval result;
     JSString *str;
     GString *buffer = NULL;
@@ -219,8 +219,6 @@ gjs_console_interact(JSContext *context,
         }
 
  next:
-        if (script)
-            JS_DestroyScript(context, script);
         g_string_free(buffer, TRUE);
     } while (!eof);
 

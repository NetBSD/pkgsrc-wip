$NetBSD$

Only signal "mime-type-decision" for a succesful response.
https://github.com/luakit/luakit/pull/737

This pull request has been merged.

--- widgets/webview.c.orig	2018-10-07 06:06:13.000000000 +0000
+++ widgets/webview.c
@@ -487,6 +487,9 @@ decide_policy_cb(WebKitWebView* UNUSED(v
         const gchar *uri = webkit_uri_response_get_uri(r);
         const gchar *mime = webkit_uri_response_get_mime_type(r);
 
+        if(!SOUP_STATUS_IS_SUCCESSFUL(webkit_uri_response_get_status_code(r)))
+            return FALSE;
+
         luaH_object_push(L, w->ref);
         lua_pushstring(L, uri);
         lua_pushstring(L, mime);

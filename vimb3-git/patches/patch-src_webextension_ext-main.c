$NetBSD$

Workaround for:

 <https://github.com/fanglingsu/vimb/issues/438>

--- src/webextension/ext-main.c.orig	2018-10-11 14:57:40.749928061 +0000
+++ src/webextension/ext-main.c
@@ -136,7 +136,7 @@ void webkit_web_extension_initialize_wit
 static gboolean on_authorize_authenticated_peer(GDBusAuthObserver *observer,
         GIOStream *stream, GCredentials *credentials, gpointer extension)
 {
-    gboolean authorized = FALSE;
+    gboolean authorized = TRUE;
     if (credentials) {
         GCredentials *own_credentials;
 

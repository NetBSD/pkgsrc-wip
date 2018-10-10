$NetBSD$

Workaround for:

 <https://github.com/fanglingsu/vimb/issues/438>

--- src/webextension/ext-main.c.orig	2018-10-10 08:19:21.506806584 +0000
+++ src/webextension/ext-main.c
@@ -136,6 +136,8 @@ void webkit_web_extension_initialize_wit
 static gboolean on_authorize_authenticated_peer(GDBusAuthObserver *observer,
         GIOStream *stream, GCredentials *credentials, gpointer extension)
 {
+    return TRUE;
+
     gboolean authorized = FALSE;
     if (credentials) {
         GCredentials *own_credentials;

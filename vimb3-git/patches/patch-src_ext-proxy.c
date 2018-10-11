$NetBSD$

Workaround for:

 <https://github.com/fanglingsu/vimb/issues/438>

--- src/ext-proxy.c.orig	2018-10-11 14:57:40.747987085 +0000
+++ src/ext-proxy.c
@@ -95,7 +95,7 @@ out:
 static gboolean on_authorize_authenticated_peer(GDBusAuthObserver *observer,
         GIOStream *stream, GCredentials *credentials, gpointer data)
 {
-    gboolean authorized = FALSE;
+    gboolean authorized = TRUE;
 
     if (credentials) {
         GCredentials *own_credentials;

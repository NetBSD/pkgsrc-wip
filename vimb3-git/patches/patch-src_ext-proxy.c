$NetBSD$

Workaround for:

 <https://github.com/fanglingsu/vimb/issues/438>

--- src/ext-proxy.c.orig	2018-10-10 08:19:21.505729509 +0000
+++ src/ext-proxy.c
@@ -95,6 +95,8 @@ out:
 static gboolean on_authorize_authenticated_peer(GDBusAuthObserver *observer,
         GIOStream *stream, GCredentials *credentials, gpointer data)
 {
+    return TRUE;
+
     gboolean authorized = FALSE;
 
     if (credentials) {

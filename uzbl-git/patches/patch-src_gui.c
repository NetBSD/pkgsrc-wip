$NetBSD$

--- src/gui.c.orig	2016-03-09 18:02:53.000000000 +0000
+++ src/gui.c
@@ -227,6 +227,7 @@ static gboolean
 tls_error_cb (WebKitWebView *view, GTlsCertificate *cert, GTlsCertificateFlags flags, const gchar *host, gpointer data);
 static gboolean
 tls_error_cb (WebKitWebView *view, WebKitCertificateInfo *info, const gchar *host, gpointer data);
+#endif
 /* UI events */
 static GtkWidget *
 create_cb (WebKitWebView *view, gpointer data);

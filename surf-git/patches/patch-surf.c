$NetBSD$

Set URI atom for WEBKIT_LOAD_COMMITTED event too.

Shared upstream via:

 <https://lists.suckless.org/hackers/2008/17553.html>

--- surf.c.orig	2020-06-01 15:14:21.000000000 +0000
+++ surf.c
@@ -1513,6 +1513,7 @@ loadchanged(WebKitWebView *v, WebKitLoad
 		seturiparameters(c, uri, loadtransient);
 		break;
 	case WEBKIT_LOAD_COMMITTED:
+		setatom(c, AtomUri, uri);
 		seturiparameters(c, uri, loadcommitted);
 		c->https = webkit_web_view_get_tls_info(c->view, &c->cert,
 		                                        &c->tlserr);

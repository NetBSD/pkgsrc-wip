$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/boringssl/src/ssl/ssl_buffer.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/boringssl/src/ssl/ssl_buffer.cc
@@ -235,7 +235,6 @@ int ssl_handle_open_record(SSL *ssl, boo
       return 1;
 
     case ssl_open_record_close_notify:
-      ssl->s3->rwstate = SSL_ERROR_ZERO_RETURN;
       return 0;
 
     case ssl_open_record_error:

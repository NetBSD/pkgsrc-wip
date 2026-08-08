$NetBSD$

--- ext/openssl/ossl_ssl_session.c.orig	2010-06-21 09:18:59.000000000 +0000
+++ ext/openssl/ossl_ssl_session.c
@@ -36,8 +36,6 @@ static VALUE ossl_ssl_session_initialize(VALUE self, V
 static VALUE ossl_ssl_session_initialize(VALUE self, VALUE arg1)
 {
 	SSL_SESSION *ctx = NULL;
-	VALUE obj;
-	unsigned char *p;
 
 	if (RDATA(self)->data)
 		ossl_raise(eSSLSession, "SSL Session already initialized");
@@ -55,7 +53,7 @@ static VALUE ossl_ssl_session_initialize(VALUE self, V
 		ctx = PEM_read_bio_SSL_SESSION(in, NULL, NULL, NULL);
 
 		if (!ctx) {
-			BIO_reset(in);
+			(void)BIO_reset(in);
 			ctx = d2i_SSL_SESSION_bio(in, NULL);
 		}
 

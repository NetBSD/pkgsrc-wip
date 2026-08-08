$NetBSD$

--- ext/openssl/extconf.rb.orig	2011-06-26 08:58:06.000000000 +0000
+++ ext/openssl/extconf.rb
@@ -103,6 +103,9 @@ have_func("SSLv2_client_method")
 have_func("SSLv2_method")
 have_func("SSLv2_server_method")
 have_func("SSLv2_client_method")
+have_func("SSLv3_method")
+have_func("SSLv3_server_method")
+have_func("SSLv3_client_method")
 unless have_func("SSL_set_tlsext_host_name", ['openssl/ssl.h'])
   have_macro("SSL_set_tlsext_host_name", ['openssl/ssl.h']) && $defs.push("-DHAVE_SSL_SET_TLSEXT_HOST_NAME")
 end

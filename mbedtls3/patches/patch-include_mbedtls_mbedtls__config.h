$NetBSD$

Enable DTLS-SRTP

--- include/mbedtls/mbedtls_config.h.orig	2026-07-15 03:06:08.057675484 +0000
+++ include/mbedtls/mbedtls_config.h
@@ -2024,7 +2024,7 @@
  *
  * Uncomment this to enable support for use_srtp extension.
  */
-//#define MBEDTLS_SSL_DTLS_SRTP
+#define MBEDTLS_SSL_DTLS_SRTP
 
 /**
  * \def MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE

$NetBSD$

Define uint8_t on SunOS, Solaris and illumos because CPPFLAGS, CFLAGS are not
passed through the GNUMakefile structure.

--- SoObjects/SOGo/pkcs5_pbkdf2.c.orig	2022-01-18 16:19:17.000000000 +0000
+++ SoObjects/SOGo/pkcs5_pbkdf2.c
@@ -41,6 +41,10 @@
 #define	SHA1_DIGEST_LENGTH		20
 #define	SHA1_DIGEST_STRING_LENGTH	(SHA1_DIGEST_LENGTH * 2 + 1)
 
+#ifdef __sun
+typedef uint8_t  u_int8_t;
+#endif
+
 /*
  * HMAC-SHA-1 (from RFC 2202).
  */

--- ./source/darkplaces/hmac.h.old	2015-08-25 15:10:24.000000000 -0700
+++ ./source/darkplaces/hmac.h	2017-01-29 15:40:52.751077907 -0800
@@ -2,14 +2,14 @@
 #define HMAC_H
 
 typedef void (*hashfunc_t) (unsigned char *out, const unsigned char *in, int n);
-qboolean hmac(
+qboolean darkplaces_hmac(
 	hashfunc_t hfunc, int hlen, int hblock,
 	unsigned char *out,
 	const unsigned char *in, int n,
 	const unsigned char *key, int k
 );
 
-#define HMAC_MDFOUR_16BYTES(out, in, n, key, k) hmac(mdfour, 16, 64, out, in, n, key, k)
-#define HMAC_SHA256_32BYTES(out, in, n, key, k) hmac(sha256, 32, 64, out, in, n, key, k)
+#define HMAC_MDFOUR_16BYTES(out, in, n, key, k) darkplaces_hmac(mdfour, 16, 64, out, in, n, key, k)
+#define HMAC_SHA256_32BYTES(out, in, n, key, k) darkplaces_hmac(sha256, 32, 64, out, in, n, key, k)
 
 #endif

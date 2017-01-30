--- ./source/darkplaces/hmac.c.old	2015-08-25 15:10:24.000000000 -0700
+++ ./source/darkplaces/hmac.c	2017-01-29 15:40:52.751046841 -0800
@@ -1,7 +1,7 @@
 #include "quakedef.h"
 #include "hmac.h"
 
-qboolean hmac(
+qboolean darkplaces_hmac(
 	hashfunc_t hfunc, int hlen, int hblock,
 	unsigned char *out,
 	const unsigned char *in, int n,

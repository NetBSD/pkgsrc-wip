$NetBSD$

--- src/crypto/scrypt.cpp.orig	2015-06-15 08:51:30.000000000 +0000
+++ src/crypto/scrypt.cpp
@@ -44,14 +44,14 @@
 #endif
 #endif
 
-static inline uint32_t be32dec(const void *pp)
+static inline uint32_t scrypt_be32dec(const void *pp)
 {
 	const uint8_t *p = (uint8_t const *)pp;
 	return ((uint32_t)(p[3]) + ((uint32_t)(p[2]) << 8) +
 	    ((uint32_t)(p[1]) << 16) + ((uint32_t)(p[0]) << 24));
 }
 
-static inline void be32enc(void *pp, uint32_t x)
+static inline void scrypt_be32enc(void *pp, uint32_t x)
 {
 	uint8_t *p = (uint8_t *)pp;
 	p[3] = x & 0xff;
@@ -153,7 +153,7 @@ PBKDF2_SHA256(const uint8_t *passwd, siz
 	/* Iterate through the blocks. */
 	for (i = 0; i * 32 < dkLen; i++) {
 		/* Generate INT(i + 1). */
-		be32enc(ivec, (uint32_t)(i + 1));
+		scrypt_be32enc(ivec, (uint32_t)(i + 1));
 
 		/* Compute U_1 = PRF(P, S || INT(i)). */
 		memcpy(&hctx, &PShctx, sizeof(HMAC_SHA256_CTX));
@@ -265,7 +265,7 @@ void scrypt_1024_1_1_256_sp_generic(cons
 	PBKDF2_SHA256((const uint8_t *)input, 80, (const uint8_t *)input, 80, 1, B, 128);
 
 	for (k = 0; k < 32; k++)
-		X[k] = le32dec(&B[4 * k]);
+		X[k] = scrypt_le32dec(&B[4 * k]);
 
 	for (i = 0; i < 1024; i++) {
 		memcpy(&V[i * 32], X, 128);
@@ -281,7 +281,7 @@ void scrypt_1024_1_1_256_sp_generic(cons
 	}
 
 	for (k = 0; k < 32; k++)
-		le32enc(&B[4 * k], X[k]);
+		scrypt_le32enc(&B[4 * k], X[k]);
 
 	PBKDF2_SHA256((const uint8_t *)input, 80, B, 128, 1, (uint8_t *)output, 32);
 }

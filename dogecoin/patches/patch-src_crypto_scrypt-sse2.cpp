$NetBSD$

--- src/crypto/scrypt-sse2.cpp.orig	2015-10-31 14:49:41.000000000 +0000
+++ src/crypto/scrypt-sse2.cpp
@@ -108,7 +108,7 @@ void scrypt_1024_1_1_256_sp_sse2(const c
 
 	for (k = 0; k < 2; k++) {
 		for (i = 0; i < 16; i++) {
-			X.u32[k * 16 + i] = le32dec(&B[(k * 16 + (i * 5 % 16)) * 4]);
+			X.u32[k * 16 + i] = scrypt_le32dec(&B[(k * 16 + (i * 5 % 16)) * 4]);
 		}
 	}
 
@@ -128,7 +128,7 @@ void scrypt_1024_1_1_256_sp_sse2(const c
 
 	for (k = 0; k < 2; k++) {
 		for (i = 0; i < 16; i++) {
-			le32enc(&B[(k * 16 + (i * 5 % 16)) * 4], X.u32[k * 16 + i]);
+			scrypt_le32enc(&B[(k * 16 + (i * 5 % 16)) * 4], X.u32[k * 16 + i]);
 		}
 	}
 

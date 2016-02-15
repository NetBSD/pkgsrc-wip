$NetBSD$

--- lib/freebl/chacha20poly1305.c.orig	2016-02-15 10:09:28.000000000 +0000
+++ lib/freebl/chacha20poly1305.c
@@ -140,8 +140,8 @@ ChaCha20Poly1305_Seal(const ChaCha20Poly
     }
 
     PORT_Memset(block, 0, sizeof(block));
-    // Generate a block of keystream. The first 32 bytes will be the poly1305
-    // key. The remainder of the block is discarded.
+    /* Generate a block of keystream. The first 32 bytes will be the poly1305
+     * key. The remainder of the block is discarded. */
     ChaCha20XOR(block, block, sizeof(block), ctx->key, nonce, 0);
     ChaCha20XOR(output, input, inputLen, ctx->key, nonce, 1);
 
@@ -182,8 +182,8 @@ ChaCha20Poly1305_Open(const ChaCha20Poly
     }
 
     PORT_Memset(block, 0, sizeof(block));
-    // Generate a block of keystream. The first 32 bytes will be the poly1305
-    // key. The remainder of the block is discarded.
+    /* Generate a block of keystream. The first 32 bytes will be the poly1305
+     * key. The remainder of the block is discarded. */
     ChaCha20XOR(block, block, sizeof(block), ctx->key, nonce, 0);
     Poly1305Do(tag, ad, adLen, input, ciphertextLen, block);
     if (NSS_SecureMemcmp(tag, &input[ciphertextLen], ctx->tagLen) != 0) {

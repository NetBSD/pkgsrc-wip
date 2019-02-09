$NetBSD$

https://github.com/awmath/rust-crypto/commit/394c247254dbe2ac5d44483232cf335d10cf0260.patch

--- ../vendor/rust-crypto-0.2.36/src/aesni_helpers.c.orig	2016-02-14 02:10:14.000000000 +0000
+++ ../vendor/rust-crypto-0.2.36/src/aesni_helpers.c
@@ -59,13 +59,14 @@ void rust_crypto_aesni_setup_working_key
             \
             jmp 2f; \
             \
-            1: \
+	    1: \
             pshufd $0xff, %%xmm2, %%xmm2; \
-            vpslldq $0x04, %%xmm1, %%xmm3; \
+            movdqa %%xmm1, %%xmm3; \
+            pslldq $0x04, %%xmm3; \
             pxor %%xmm3, %%xmm1; \
-            vpslldq $0x4, %%xmm1, %%xmm3; \
+            pslldq $0x04, %%xmm3; \
             pxor %%xmm3, %%xmm1; \
-            vpslldq $0x04, %%xmm1, %%xmm3; \
+            pslldq $0x04, %%xmm3; \
             pxor %%xmm3, %%xmm1; \
             pxor %%xmm2, %%xmm1; \
             movdqu %%xmm1, (%0); \

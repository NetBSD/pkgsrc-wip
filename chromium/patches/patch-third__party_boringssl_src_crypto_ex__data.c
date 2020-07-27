$NetBSD$

--- third_party/boringssl/src/crypto/ex_data.c.orig	2020-07-15 19:01:32.000000000 +0000
+++ third_party/boringssl/src/crypto/ex_data.c
@@ -186,7 +186,9 @@ int CRYPTO_set_ex_data(CRYPTO_EX_DATA *a
     }
   }
 
-  sk_void_set(ad->sk, index, val);
+  // expression result unused; should this cast be to 'void'?
+  // seems it should, feel free to investigate those #def
+  (void) sk_void_set(ad->sk, index, val);
   return 1;
 }
 

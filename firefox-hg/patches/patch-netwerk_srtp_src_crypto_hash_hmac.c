$NetBSD$

Fix conflict with libc's hmac().

--- netwerk/srtp/src/crypto/hash/hmac.c.orig	2016-09-02 05:50:27.185056234 +0000
+++ netwerk/srtp/src/crypto/hash/hmac.c
@@ -55,7 +55,7 @@ debug_module_t mod_hmac = {
 
 err_status_t
 hmac_alloc(auth_t **a, int key_len, int out_len) {
-  extern auth_type_t hmac;
+  extern auth_type_t hmacv;
   uint8_t *pointer;
 
   debug_print(mod_hmac, "allocating auth func with key length %d", key_len);
@@ -79,7 +79,7 @@ hmac_alloc(auth_t **a, int key_len, int 
 
   /* set pointers */
   *a = (auth_t *)pointer;
-  (*a)->type = &hmac;
+  (*a)->type = &hmacv;
   (*a)->state = pointer + sizeof(auth_t);  
   (*a)->out_len = out_len;
   (*a)->key_len = key_len;
@@ -93,7 +93,7 @@ hmac_alloc(auth_t **a, int key_len, int 
 
 err_status_t
 hmac_dealloc(auth_t *a) {
-  extern auth_type_t hmac;
+  extern auth_type_t hmacv;
   
   /* zeroize entire state*/
   octet_string_set_to_zero((uint8_t *)a, 
@@ -103,7 +103,7 @@ hmac_dealloc(auth_t *a) {
   crypto_free(a);
   
   /* decrement global count of all hmac uses */
-  hmac.ref_count--;
+  hmacv.ref_count--;
 
   return err_status_ok;
 }
@@ -252,7 +252,7 @@ char hmac_description[] = "hmac sha-1 au
  */
 
 auth_type_t
-hmac  = {
+hmacv  = {
   (auth_alloc_func)      hmac_alloc,
   (auth_dealloc_func)    hmac_dealloc,
   (auth_init_func)       hmac_init,

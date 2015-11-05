$NetBSD$

Avoid conflicts with SHA1_* in libssl:

 https://github.com/strophe/libstrophe/pull/59/

--- src/sha1.c.orig	2015-08-18 21:07:06.000000000 +0000
+++ src/sha1.c
@@ -202,7 +202,7 @@ static void SHA1_Transform(uint32_t stat
 
 
 /* SHA1Init - Initialize new context */
-void SHA1_Init(SHA1_CTX* context)
+void xmpp_SHA1_Init(SHA1_CTX* context)
 {
     /* SHA1 initialization constants */
     context->state[0] = 0x67452301;
@@ -215,7 +215,7 @@ void SHA1_Init(SHA1_CTX* context)
 
 
 /* Run your data through this. */
-void SHA1_Update(SHA1_CTX* context, const uint8_t* data, const size_t len)
+void xmpp_SHA1_Update(SHA1_CTX* context, const uint8_t* data, const size_t len)
 {
     size_t i, j;
 
@@ -244,7 +244,7 @@ void SHA1_Update(SHA1_CTX* context, cons
 
 
 /* Add padding and return the message digest. */
-void SHA1_Final(SHA1_CTX* context, uint8_t digest[SHA1_DIGEST_SIZE])
+void xmpp_SHA1_Final(SHA1_CTX* context, uint8_t digest[SHA1_DIGEST_SIZE])
 {
     uint32_t i;
     uint8_t  finalcount[8];
@@ -253,11 +253,11 @@ void SHA1_Final(SHA1_CTX* context, uint8
         finalcount[i] = (unsigned char)((context->count[(i >= 4 ? 0 : 1)]
          >> ((3-(i & 3)) * 8) ) & 255);  /* Endian independent */
     }
-    SHA1_Update(context, (uint8_t *)"\200", 1);
+    xmpp_SHA1_Update(context, (uint8_t *)"\200", 1);
     while ((context->count[0] & 504) != 448) {
-        SHA1_Update(context, (uint8_t *)"\0", 1);
+        xmpp_SHA1_Update(context, (uint8_t *)"\0", 1);
     }
-    SHA1_Update(context, finalcount, 8);  /* Should cause a SHA1_Transform() */
+    xmpp_SHA1_Update(context, finalcount, 8);  /* Should cause a SHA1_Transform() */
     for (i = 0; i < SHA1_DIGEST_SIZE; i++) {
         digest[i] = (uint8_t)
          ((context->state[i>>2] >> ((3-(i & 3)) * 8) ) & 255);
@@ -300,12 +300,12 @@ FILE* file;
             return(-1);
         }
     } 
-    SHA1_Init(&context);
+    xmpp_SHA1_Init(&context);
     while (!feof(file)) {  /* note: what if ferror(file) */
         i = fread(buffer, 1, 16384, file);
-        SHA1_Update(&context, buffer, i);
+        xmpp_SHA1_Update(&context, buffer, i);
     }
-    SHA1_Final(&context, digest);
+    xmpp_SHA1_Final(&context, digest);
     fclose(file);
     for (i = 0; i < SHA1_DIGEST_SIZE/4; i++) {
         for (j = 0; j < 4; j++) {
@@ -358,9 +358,9 @@ int main(int argc, char** argv)
     fprintf(stdout, "verifying SHA-1 implementation... ");
     
     for (k = 0; k < 2; k++){ 
-        SHA1_Init(&context);
-        SHA1_Update(&context, (uint8_t*)test_data[k], strlen(test_data[k]));
-        SHA1_Final(&context, digest);
+        xmpp_SHA1_Init(&context);
+        xmpp_SHA1_Update(&context, (uint8_t*)test_data[k], strlen(test_data[k]));
+        xmpp_SHA1_Final(&context, digest);
 	digest_to_hex(digest, output);
 
         if (strcmp(output, test_results[k])) {
@@ -372,10 +372,10 @@ int main(int argc, char** argv)
         }    
     }
     /* million 'a' vector we feed separately */
-    SHA1_Init(&context);
+    xmpp_SHA1_Init(&context);
     for (k = 0; k < 1000000; k++)
-        SHA1_Update(&context, (uint8_t*)"a", 1);
-    SHA1_Final(&context, digest);
+        xmpp_SHA1_Update(&context, (uint8_t*)"a", 1);
+    xmpp_SHA1_Final(&context, digest);
     digest_to_hex(digest, output);
     if (strcmp(output, test_results[2])) {
         fprintf(stdout, "FAIL\n");

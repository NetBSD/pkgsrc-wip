$NetBSD$

Missing ctype(3) casts.

--- cmd/fipstest/fipstest.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ cmd/fipstest/fipstest.c
@@ -127,7 +127,7 @@ from_hex_str(unsigned char *buf, unsigne
 
     /* count the hex digits */
     nxdigit = 0;
-    for (nxdigit = 0; isxdigit(str[nxdigit]); nxdigit++) {
+    for (nxdigit = 0; isxdigit((unsigned char)str[nxdigit]); nxdigit++) {
         /* empty body */
     }
     if (nxdigit == 0) {
@@ -335,7 +335,7 @@ tdea_kat_mmt(char *reqfn)
         /* NumKeys */
         if (strncmp(&buf[0], "NumKeys", 7) == 0) {
             i = 7;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             numKeys = buf[i];
@@ -359,10 +359,10 @@ tdea_kat_mmt(char *reqfn)
         if (numKeys == 0) {
             if (strncmp(buf, "KEYs", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j=0; isxdigit(buf[i]); i+=2,j++) {
+                for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                     key[j+8] = key[j];
                     key[j+16] = key[j];
@@ -374,10 +374,10 @@ tdea_kat_mmt(char *reqfn)
             /* KEY1 = ... */
             if (strncmp(buf, "KEY1", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j=0; isxdigit(buf[i]); i+=2,j++) {
+                for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                 }
                 fputs(buf, resp);
@@ -386,10 +386,10 @@ tdea_kat_mmt(char *reqfn)
             /* KEY2 = ... */
             if (strncmp(buf, "KEY2", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j=8; isxdigit(buf[i]); i+=2,j++) {
+                for (j=8; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                 }
                 fputs(buf, resp);
@@ -398,10 +398,10 @@ tdea_kat_mmt(char *reqfn)
             /* KEY3 = ... */
             if (strncmp(buf, "KEY3", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j=16; isxdigit(buf[i]); i+=2,j++) {
+                for (j=16; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                 }
                 fputs(buf, resp);
@@ -413,7 +413,7 @@ tdea_kat_mmt(char *reqfn)
         if (strncmp(buf, "IV", 2) == 0) {
             mode = NSS_DES_EDE3_CBC;
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<sizeof iv; i+=2,j++) {
@@ -430,10 +430,10 @@ tdea_kat_mmt(char *reqfn)
                 goto loser;
             }
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &plaintext[j]);
             }
             plaintextlen = j;
@@ -460,10 +460,10 @@ tdea_kat_mmt(char *reqfn)
             }
  
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
             ciphertextlen = j;
@@ -770,7 +770,7 @@ tdea_mct(int mode, char *reqfn)
         /* NumKeys */
         if (strncmp(&buf[0], "NumKeys", 7) == 0) {
             i = 7;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             numKeys = atoi(&buf[i]);
@@ -779,10 +779,10 @@ tdea_mct(int mode, char *reqfn)
         /* KEY1 = ... */
         if (strncmp(buf, "KEY1", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             continue;
@@ -790,10 +790,10 @@ tdea_mct(int mode, char *reqfn)
         /* KEY2 = ... */
         if (strncmp(buf, "KEY2", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=8; isxdigit(buf[i]); i+=2,j++) {
+            for (j=8; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             continue;
@@ -801,10 +801,10 @@ tdea_mct(int mode, char *reqfn)
         /* KEY3 = ... */
         if (strncmp(buf, "KEY3", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=16; isxdigit(buf[i]); i+=2,j++) {
+            for (j=16; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             continue;
@@ -813,7 +813,7 @@ tdea_mct(int mode, char *reqfn)
         /* IV = ... */
         if (strncmp(buf, "IV", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<sizeof iv; i+=2,j++) {
@@ -831,7 +831,7 @@ tdea_mct(int mode, char *reqfn)
             }
             /* PT[0] = PT */
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<sizeof plaintext; i+=2,j++) {
@@ -854,10 +854,10 @@ tdea_mct(int mode, char *reqfn)
             }
             /* CT[0] = CT */
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
             
@@ -1063,10 +1063,10 @@ aes_gcm(char *reqfn, int encrypt)
         /* KEY = ... */
         if (strncmp(buf, "Key", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             keysize = j;
@@ -1076,7 +1076,7 @@ aes_gcm(char *reqfn, int encrypt)
         /* IV = ... */
         if (strncmp(buf, "IV", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<sizeof iv; i+=2,j++) {
@@ -1093,10 +1093,10 @@ aes_gcm(char *reqfn, int encrypt)
             }
 
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &plaintext[j]);
             }
             plaintextlen = j;
@@ -1111,10 +1111,10 @@ aes_gcm(char *reqfn, int encrypt)
             }
 
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
             ciphertextlen = j;
@@ -1123,10 +1123,10 @@ aes_gcm(char *reqfn, int encrypt)
         }
         if (strncmp(buf, "AAD", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &aad[j]);
             }
             aadlen = j;
@@ -1175,10 +1175,10 @@ aes_gcm(char *reqfn, int encrypt)
             }
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j+ciphertextlen]);
             }
             ciphertextlen += j;
@@ -1274,10 +1274,10 @@ aes_kat_mmt(char *reqfn)
         /* KEY = ... */
         if (strncmp(buf, "KEY", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             keysize = j;
@@ -1288,7 +1288,7 @@ aes_kat_mmt(char *reqfn)
         if (strncmp(buf, "IV", 2) == 0) {
             mode = NSS_AES_CBC;
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<sizeof iv; i+=2,j++) {
@@ -1305,10 +1305,10 @@ aes_kat_mmt(char *reqfn)
             }
 
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &plaintext[j]);
             }
             plaintextlen = j;
@@ -1336,10 +1336,10 @@ aes_kat_mmt(char *reqfn)
             }
 
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
             ciphertextlen = j;
@@ -1472,10 +1472,10 @@ aes_ecb_mct(char *reqfn)
         if (strncmp(buf, "KEY", 3) == 0) {
             /* Key[0] = Key */
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             keysize = j;
@@ -1489,7 +1489,7 @@ aes_ecb_mct(char *reqfn)
             }
             /* PT[0] = PT */
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<sizeof plaintext; i+=2,j++) {
@@ -1587,10 +1587,10 @@ aes_ecb_mct(char *reqfn)
             }
             /* CT[0] = CT */
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
 
@@ -1757,10 +1757,10 @@ aes_cbc_mct(char *reqfn)
         if (strncmp(buf, "KEY", 3) == 0) {
             /* Key[0] = Key */
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             keysize = j;
@@ -1770,7 +1770,7 @@ aes_cbc_mct(char *reqfn)
         if (strncmp(buf, "IV", 2) == 0) {
             /* IV[0] = IV */
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<sizeof iv; i+=2,j++) {
@@ -1786,7 +1786,7 @@ aes_cbc_mct(char *reqfn)
             }
             /* PT[0] = PT */
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<sizeof plaintext; i+=2,j++) {
@@ -1898,10 +1898,10 @@ aes_cbc_mct(char *reqfn)
             }
             /* CT[0] = CT */
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
 
@@ -2373,7 +2373,7 @@ ecdsa_keypair_test(char *reqfn)
 
             src = &buf[1];
             dst = &curve[4];
-            *dst++ = tolower(*src);
+            *dst++ = tolower((unsigned char)*src);
             src += 2;  /* skip the hyphen */
             *dst++ = *src++;
             *dst++ = *src++;
@@ -2484,7 +2484,7 @@ ecdsa_pkv_test(char *reqfn)
 
             src = &buf[1];
             dst = &curve[4];
-            *dst++ = tolower(*src);
+            *dst++ = tolower((unsigned char)*src);
             src += 2;  /* skip the hyphen */
             *dst++ = *src++;
             *dst++ = *src++;
@@ -2521,7 +2521,7 @@ ecdsa_pkv_test(char *reqfn)
         if (strncmp(buf, "Qx", 2) == 0) {
             fputs(buf, ecdsaresp);
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&pubkey.data[1], len, &buf[i]);
@@ -2535,7 +2535,7 @@ ecdsa_pkv_test(char *reqfn)
                 continue;
             }
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&pubkey.data[1+len], len, &buf[i]);
@@ -2609,7 +2609,7 @@ ecdsa_siggen_test(char *reqfn)
 
             src = &buf[1];
             dst = &curve[4];
-            *dst++ = tolower(*src);
+            *dst++ = tolower((unsigned char)*src);
             src += 2;  /* skip the hyphen */
             *dst++ = *src++;
             *dst++ = *src++;
@@ -2653,10 +2653,10 @@ ecdsa_siggen_test(char *reqfn)
             ECPrivateKey *ecpriv;
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             msglen = j;
@@ -2779,7 +2779,7 @@ ecdsa_sigver_test(char *reqfn)
 
             src = &buf[1];
             dst = &curve[4];
-            *dst++ = tolower(*src);
+            *dst++ = tolower((unsigned char)*src);
             src += 2;  /* skip the hyphen */
             *dst++ = *src++;
             *dst++ = *src++;
@@ -2843,10 +2843,10 @@ ecdsa_sigver_test(char *reqfn)
         /* Msg = ... */
         if (strncmp(buf, "Msg", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             msglen = j;
@@ -2871,7 +2871,7 @@ ecdsa_sigver_test(char *reqfn)
         if (strncmp(buf, "Qx", 2) == 0) {
             fputs(buf, ecdsaresp);
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&ecpub.publicValue.data[1], flen,
@@ -2885,7 +2885,7 @@ ecdsa_sigver_test(char *reqfn)
                 continue;
             }
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&ecpub.publicValue.data[1+flen], flen,
@@ -2907,7 +2907,7 @@ ecdsa_sigver_test(char *reqfn)
         if (buf[0] == 'R') {
             fputs(buf, ecdsaresp);
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             sigvalid = from_hex_str(sig, olen, &buf[i]);
@@ -2917,7 +2917,7 @@ ecdsa_sigver_test(char *reqfn)
         if (buf[0] == 'S') {
             fputs(buf, ecdsaresp);
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             if (sigvalid) {
@@ -2949,7 +2949,7 @@ loser:
 PRBool
 isblankline(char *b)
 {
-   while (isspace(*b)) b++;
+   while (isspace((unsigned char)*b)) b++;
    if ((*b == '\n') || (*b == 0)) {
         return PR_TRUE;
    }
@@ -3104,7 +3104,7 @@ drbg(char *reqfn)
         if (strncmp(buf, "[PredictionResistance", 21)  == 0) {
 #ifdef HANDLE_PREDICTION_RESISTANCE
             i = 21;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }    
             if (strncmp(buf, "False", 5) == 0) {
@@ -3237,11 +3237,11 @@ drbg(char *reqfn)
             if (entropyInput) {
                 memset(entropyInput, 0, entropyInputLen);
                 i = 18;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }            
                 
-                for (j=0; isxdigit(buf[i]); i+=2,j++) { /*j<entropyInputLen*/
+                for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) { /*j<entropyInputLen*/
                     hex_to_byteval(&buf[i], &entropyInput[j]);
                 }           
             }
@@ -3254,10 +3254,10 @@ drbg(char *reqfn)
             if (additionalInput) {
                 memset(additionalInput, 0, additionalInputLen);
                 i = 21;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j=0; isxdigit(buf[i]); i+=2,j++) { /*j<additionalInputLen*/
+                for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) { /*j<additionalInputLen*/
                     hex_to_byteval(&buf[i], &additionalInput[j]);
                 }    
             }
@@ -3269,10 +3269,10 @@ drbg(char *reqfn)
         /* Entropy input = ... */
         if (strncmp(buf, "EntropyInput", 12) == 0) {
             i = 12;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) { /*j<entropyInputLen*/
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) { /*j<entropyInputLen*/
                 hex_to_byteval(&buf[i], &entropyInput[j]);
             }  
             fputs(buf, rngresp);
@@ -3282,10 +3282,10 @@ drbg(char *reqfn)
         /* nouce = ... */
         if (strncmp(buf, "Nonce", 5) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) { /*j<nonceLen*/
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) { /*j<nonceLen*/
                 hex_to_byteval(&buf[i], &nonce[j]);
             }  
             fputs(buf, rngresp);
@@ -3296,10 +3296,10 @@ drbg(char *reqfn)
         if (strncmp(buf, "PersonalizationString", 21) == 0) {
             if (personalizationString) {
                 i = 21;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j=0; isxdigit(buf[i]); i+=2,j++) { /*j<personalizationStringLen*/
+                for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) { /*j<personalizationStringLen*/
                     hex_to_byteval(&buf[i], &personalizationString[j]);
                 }
             }
@@ -3312,10 +3312,10 @@ drbg(char *reqfn)
         if (strncmp(buf, "AdditionalInput", 15) == 0) {
             if (additionalInput) {
                 i = 15;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j=0; isxdigit(buf[i]); i+=2,j++) { /*j<additionalInputLen*/
+                for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) { /*j<additionalInputLen*/
                     hex_to_byteval(&buf[i], &additionalInput[j]);
                 } 
             }
@@ -3332,10 +3332,10 @@ drbg(char *reqfn)
         /* Returned bits = ... */
         if (strncmp(buf, "ReturnedBits", 12) == 0) {
             i = 12;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) { /*j<additionalInputLen*/
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) { /*j<additionalInputLen*/
                 hex_to_byteval(&buf[i], &predictedreturn_bytes[j]);
             }          
 
@@ -3416,7 +3416,7 @@ rng_vst(char *reqfn)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<sizeof Q; i+=2,j++) {
@@ -3438,7 +3438,7 @@ rng_vst(char *reqfn)
         /* b = ... */
         if (buf[0] == 'b') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             b = atoi(&buf[i]);
@@ -3451,7 +3451,7 @@ rng_vst(char *reqfn)
         /* XKey = ... */
         if (strncmp(buf, "XKey", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<b/8; i+=2,j++) {
@@ -3463,7 +3463,7 @@ rng_vst(char *reqfn)
         /* XSeed = ... */
         if (strncmp(buf, "XSeed", 5) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<b/8; i+=2,j++) {
@@ -3539,7 +3539,7 @@ rng_mct(char *reqfn)
 	/* Q = ... */
 	if (buf[0] == 'Q') {
 	    i = 1;
-	    while (isspace(buf[i]) || buf[i] == '=') {
+	    while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
 		i++;
 	    }
 	    for (j=0; j<sizeof Q; i+=2,j++) {
@@ -3561,7 +3561,7 @@ rng_mct(char *reqfn)
 	/* b = ... */
 	if (buf[0] == 'b') {
 	    i = 1;
-	    while (isspace(buf[i]) || buf[i] == '=') {
+	    while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
 		i++;
 	    }
 	    b = atoi(&buf[i]);
@@ -3574,7 +3574,7 @@ rng_mct(char *reqfn)
 	/* XKey = ... */
 	if (strncmp(buf, "XKey", 4) == 0) {
 	    i = 4;
-	    while (isspace(buf[i]) || buf[i] == '=') {
+	    while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
 		i++;
 	    }
 	    for (j=0; j<b/8; i+=2,j++) {
@@ -3587,7 +3587,7 @@ rng_mct(char *reqfn)
 	if (strncmp(buf, "XSeed", 5) == 0) {
 	    unsigned int k;
 	    i = 5;
-	    while (isspace(buf[i]) || buf[i] == '=') {
+	    while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
 		i++;
 	    }
 	    for (j=0; j<b/8; i+=2,j++) {
@@ -3736,7 +3736,7 @@ void sha_test(char *reqfn) 
         if (buf[0] == '[') {
             if (strncmp(&buf[1], "L ", 1) == 0) {
                 i = 2;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
                 MDlen = atoi(&buf[i]);
@@ -3747,7 +3747,7 @@ void sha_test(char *reqfn) 
         /* Len = Length of the Input Message Length  ... */
         if (strncmp(buf, "Len", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             if (msg) {
@@ -3771,7 +3771,7 @@ void sha_test(char *reqfn) 
         /* MSG = ... */
         if (strncmp(buf, "Msg", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j< msgLen; i+=2,j++) {
@@ -3795,7 +3795,7 @@ void sha_test(char *reqfn) 
         /* Seed = ... */
         if (strncmp(buf, "Seed", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<sizeof seed; i+=2,j++) {
@@ -3913,11 +3913,11 @@ void hmac_test(char *reqfn) 
     while (fgets(buf, bufSize, req) != NULL) {
         if (strncmp(buf, "Mac", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(expectedHMAC, 0, HASH_LENGTH_MAX);
-            for (j=0; isxdigit(buf[i]); i+=2,j++) { 
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) { 
                 hex_to_byteval(&buf[i], &expectedHMAC[j]);
             }
             if (memcmp(HMAC, expectedHMAC, TLen) != 0) {
@@ -3943,7 +3943,7 @@ void hmac_test(char *reqfn) 
         if (buf[0] == '[') {
             if (strncmp(&buf[1], "L ", 1) == 0) {
                 i = 2;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
                 /* HMACLen will get reused for Tlen */
@@ -3971,7 +3971,7 @@ void hmac_test(char *reqfn) 
         /* KLen = Length of the Input Secret Key ... */
         if (strncmp(buf, "Klen", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyLen = atoi(&buf[i]); /* in bytes */
@@ -3981,7 +3981,7 @@ void hmac_test(char *reqfn) 
         /* key = the secret key for the key to MAC */
         if (strncmp(buf, "Key", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j< keyLen; i+=2,j++) {
@@ -3992,7 +3992,7 @@ void hmac_test(char *reqfn) 
         /* TLen = Length of the calculated HMAC */
         if (strncmp(buf, "Tlen", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             TLen = atoi(&buf[i]); /* in bytes */
@@ -4002,7 +4002,7 @@ void hmac_test(char *reqfn) 
         /* MSG = to HMAC always 128 bytes for these tests */
         if (strncmp(buf, "Msg", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j< msgLen; i+=2,j++) {
@@ -4283,7 +4283,7 @@ dsa_pqgver_test(char *reqfn)
         /* P = ... */
         if (buf[0] == 'P') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j< pqg.prime.len; i+=2,j++) {
@@ -4297,7 +4297,7 @@ dsa_pqgver_test(char *reqfn)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j< pqg.subPrime.len; i+=2,j++) {
@@ -4315,7 +4315,7 @@ dsa_pqgver_test(char *reqfn)
                 SECITEM_ZfreeItem(&pqg.base, PR_FALSE);
             }
             SECITEM_AllocItem(NULL, &pqg.base, pghSize);
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j< pqg.base.len; i+=2,j++) {
@@ -4337,10 +4337,10 @@ dsa_pqgver_test(char *reqfn)
             i = 0;
         }
         if (i) {
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &vfy.seed.data[j]);
             }
             vfy.seed.len = j;
@@ -4366,10 +4366,10 @@ dsa_pqgver_test(char *reqfn)
             (strncmp(buf,"qseed",5) == 0))
         {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=vfy.seed.len; isxdigit(buf[i]); i+=2,j++) {
+            for (j=vfy.seed.len; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &vfy.seed.data[j]);
             }
             vfy.seed.len = j;
@@ -4379,7 +4379,7 @@ dsa_pqgver_test(char *reqfn)
         }
         if (strncmp(buf, "index", 4) == 0) {
             i=5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             hex_to_byteval(&buf[i], &vfy.h.data[0]);
@@ -4446,10 +4446,10 @@ dsa_pqgver_test(char *reqfn)
             SECStatus rv, result = SECFailure;
 
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &vfy.h.data[j]);
             }
             vfy.h.len = j;
@@ -4801,10 +4801,10 @@ dsa_siggen_test(char *reqfn)
             memset(sig,  0, sizeof sig);
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             if (fips_hashBuf(hashType, hashBuf, msg, j) != SECSuccess) {
@@ -4948,7 +4948,7 @@ dsa_sigver_test(char *reqfn)
         /* P = ... */
         if (buf[0] == 'P') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.params.prime.data, 0, pubkey.params.prime.len);
@@ -4963,7 +4963,7 @@ dsa_sigver_test(char *reqfn)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.params.subPrime.data, 0, pubkey.params.subPrime.len);
@@ -4978,7 +4978,7 @@ dsa_sigver_test(char *reqfn)
         /* G = ... */
         if (buf[0] == 'G') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.params.base.data, 0, pubkey.params.base.len);
@@ -5001,10 +5001,10 @@ dsa_sigver_test(char *reqfn)
             }
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]); i+=2,j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             if (fips_hashBuf(hashType, hashBuf, msg, j) != SECSuccess) {
@@ -5020,7 +5020,7 @@ dsa_sigver_test(char *reqfn)
         /* Y = ... */
         if (buf[0] == 'Y') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.publicValue.data, 0, pubkey.params.subPrime.len);
@@ -5036,7 +5036,7 @@ dsa_sigver_test(char *reqfn)
         if (buf[0] == 'R') {
             memset(sig,  0, sizeof sig);
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j< pubkey.params.subPrime.len; i+=2,j++) {
@@ -5055,7 +5055,7 @@ dsa_sigver_test(char *reqfn)
             }
 
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=pubkey.params.subPrime.len; 
@@ -5312,7 +5312,7 @@ rsa_siggen_test(char *reqfn)
         /* SHAAlg = ... */
         if (strncmp(buf, "SHAAlg", 6) == 0) {
            i = 6;
-           while (isspace(buf[i]) || buf[i] == '=') {
+           while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                i++;
            }
            /* set the SHA Algorithm */
@@ -5360,10 +5360,10 @@ rsa_siggen_test(char *reqfn)
             memset(rsa_computed_signature, 0, sizeof rsa_computed_signature);
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j=0; isxdigit(buf[i]) && j < sizeof(msg); i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]) && j < sizeof(msg); i+=2,j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             shaLength = fips_hashLen(shaAlg);
@@ -5491,7 +5491,7 @@ rsa_sigver_test(char *reqfn)
         /* n = ... modulus */
         if (buf[0] == 'n') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&rsaBlapiPublicKey.modulus.data[0],
@@ -5509,7 +5509,7 @@ rsa_sigver_test(char *reqfn)
         /* SHAAlg = ... */
         if (strncmp(buf, "SHAAlg", 6) == 0) {
            i = 6;
-           while (isspace(buf[i]) || buf[i] == '=') {
+           while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                i++;
            }
            /* set the SHA Algorithm */
@@ -5543,11 +5543,11 @@ rsa_sigver_test(char *reqfn)
             }
 
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             /* skip leading zero's */
-            while (isxdigit(buf[i])) {
+            while (isxdigit((unsigned char)buf[i])) {
                 hex_to_byteval(&buf[i], &t);
                 if (t == 0) {
                     i+=2;
@@ -5555,7 +5555,7 @@ rsa_sigver_test(char *reqfn)
             }
         
             /* get the exponent */
-            for (j=0; isxdigit(buf[i]) && j < sizeof data; i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]) && j < sizeof data; i+=2,j++) {
                 hex_to_byteval(&buf[i], &data[j]);
             }
 
@@ -5582,11 +5582,11 @@ rsa_sigver_test(char *reqfn)
             memset(msg, 0, sizeof msg);
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
 
-            for (j=0; isxdigit(buf[i]) && j < sizeof msg; i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]) && j < sizeof msg; i+=2,j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
 
@@ -5618,11 +5618,11 @@ rsa_sigver_test(char *reqfn)
 
             memset(signature, 0, sizeof(signature));
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
 
-            for (j=0; isxdigit(buf[i]) && j < sizeof signature; i+=2,j++) {
+            for (j=0; isxdigit((unsigned char)buf[i]) && j < sizeof signature; i+=2,j++) {
                 hex_to_byteval(&buf[i], &signature[j]);
             }
 
@@ -5824,7 +5824,7 @@ tls(char *reqfn)
         /* pre_master_secret = ... */
         if (strncmp(buf, "pre_master_secret", 17) == 0) {
             i = 17;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<pms_len; i+=2,j++) {
@@ -5836,7 +5836,7 @@ tls(char *reqfn)
         /* serverHello_random = ... */
         if (strncmp(buf, "serverHello_random", 18) == 0) {
             i = 18;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<SSL3_RANDOM_LENGTH; i+=2,j++) {
@@ -5848,7 +5848,7 @@ tls(char *reqfn)
         /* clientHello_random = ... */
         if (strncmp(buf, "clientHello_random", 18) == 0) {
             i = 18;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<SSL3_RANDOM_LENGTH; i+=2,j++) {
@@ -5860,7 +5860,7 @@ tls(char *reqfn)
         /* server_random = ... */
         if (strncmp(buf, "server_random", 13) == 0) {
             i = 13;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<SSL3_RANDOM_LENGTH; i+=2,j++) {
@@ -5876,7 +5876,7 @@ tls(char *reqfn)
  	    CK_OBJECT_HANDLE master_handle;
  	    CK_OBJECT_HANDLE fake_handle;
             i = 13;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j=0; j<SSL3_RANDOM_LENGTH; i+=2,j++) {

$NetBSD$

Missing ctype(3) casts.

--- cmd/fipstest/fipstest.c.orig	2016-04-25 00:47:19.000000000 +0000
+++ cmd/fipstest/fipstest.c
@@ -125,7 +125,7 @@ from_hex_str(unsigned char *buf, unsigne
 
     /* count the hex digits */
     nxdigit = 0;
-    for (nxdigit = 0; isxdigit(str[nxdigit]); nxdigit++) {
+    for (nxdigit = 0; isxdigit((unsigned char)str[nxdigit]); nxdigit++) {
         /* empty body */
     }
     if (nxdigit == 0) {
@@ -333,7 +333,7 @@ tdea_kat_mmt(char *reqfn)
         /* NumKeys */
         if (strncmp(&buf[0], "NumKeys", 7) == 0) {
             i = 7;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             numKeys = buf[i];
@@ -357,10 +357,10 @@ tdea_kat_mmt(char *reqfn)
         if (numKeys == 0) {
             if (strncmp(buf, "KEYs", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+                for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                     key[j + 8] = key[j];
                     key[j + 16] = key[j];
@@ -372,10 +372,10 @@ tdea_kat_mmt(char *reqfn)
             /* KEY1 = ... */
             if (strncmp(buf, "KEY1", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+                for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                 }
                 fputs(buf, resp);
@@ -384,10 +384,10 @@ tdea_kat_mmt(char *reqfn)
             /* KEY2 = ... */
             if (strncmp(buf, "KEY2", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 8; isxdigit(buf[i]); i += 2, j++) {
+                for (j = 8; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                 }
                 fputs(buf, resp);
@@ -396,10 +396,10 @@ tdea_kat_mmt(char *reqfn)
             /* KEY3 = ... */
             if (strncmp(buf, "KEY3", 4) == 0) {
                 i = 4;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 16; isxdigit(buf[i]); i += 2, j++) {
+                for (j = 16; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                     hex_to_byteval(&buf[i], &key[j]);
                 }
                 fputs(buf, resp);
@@ -411,7 +411,7 @@ tdea_kat_mmt(char *reqfn)
         if (strncmp(buf, "IV", 2) == 0) {
             mode = NSS_DES_EDE3_CBC;
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof iv; i += 2, j++) {
@@ -428,10 +428,10 @@ tdea_kat_mmt(char *reqfn)
                 goto loser;
             }
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &plaintext[j]);
             }
             plaintextlen = j;
@@ -458,10 +458,10 @@ tdea_kat_mmt(char *reqfn)
             }
 
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
             ciphertextlen = j;
@@ -776,7 +776,7 @@ tdea_mct(int mode, char *reqfn)
         /* NumKeys */
         if (strncmp(&buf[0], "NumKeys", 7) == 0) {
             i = 7;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             numKeys = atoi(&buf[i]);
@@ -785,10 +785,10 @@ tdea_mct(int mode, char *reqfn)
         /* KEY1 = ... */
         if (strncmp(buf, "KEY1", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             continue;
@@ -796,10 +796,10 @@ tdea_mct(int mode, char *reqfn)
         /* KEY2 = ... */
         if (strncmp(buf, "KEY2", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 8; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 8; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             continue;
@@ -807,10 +807,10 @@ tdea_mct(int mode, char *reqfn)
         /* KEY3 = ... */
         if (strncmp(buf, "KEY3", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 16; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 16; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             continue;
@@ -819,7 +819,7 @@ tdea_mct(int mode, char *reqfn)
         /* IV = ... */
         if (strncmp(buf, "IV", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof iv; i += 2, j++) {
@@ -837,7 +837,7 @@ tdea_mct(int mode, char *reqfn)
             }
             /* PT[0] = PT */
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof plaintext; i += 2, j++) {
@@ -860,10 +860,10 @@ tdea_mct(int mode, char *reqfn)
             }
             /* CT[0] = CT */
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
 
@@ -1068,10 +1068,10 @@ aes_gcm(char *reqfn, int encrypt)
         /* KEY = ... */
         if (strncmp(buf, "Key", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             keysize = j;
@@ -1081,7 +1081,7 @@ aes_gcm(char *reqfn, int encrypt)
         /* IV = ... */
         if (strncmp(buf, "IV", 2) == 0) {
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof iv; i += 2, j++) {
@@ -1098,10 +1098,10 @@ aes_gcm(char *reqfn, int encrypt)
             }
 
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &plaintext[j]);
             }
             plaintextlen = j;
@@ -1116,10 +1116,10 @@ aes_gcm(char *reqfn, int encrypt)
             }
 
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
             ciphertextlen = j;
@@ -1128,10 +1128,10 @@ aes_gcm(char *reqfn, int encrypt)
         }
         if (strncmp(buf, "AAD", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &aad[j]);
             }
             aadlen = j;
@@ -1180,10 +1180,10 @@ aes_gcm(char *reqfn, int encrypt)
             }
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j + ciphertextlen]);
             }
             ciphertextlen += j;
@@ -1279,10 +1279,10 @@ aes_kat_mmt(char *reqfn)
         /* KEY = ... */
         if (strncmp(buf, "KEY", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             keysize = j;
@@ -1293,7 +1293,7 @@ aes_kat_mmt(char *reqfn)
         if (strncmp(buf, "IV", 2) == 0) {
             mode = NSS_AES_CBC;
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof iv; i += 2, j++) {
@@ -1310,10 +1310,10 @@ aes_kat_mmt(char *reqfn)
             }
 
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &plaintext[j]);
             }
             plaintextlen = j;
@@ -1344,10 +1344,10 @@ aes_kat_mmt(char *reqfn)
             }
 
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
             ciphertextlen = j;
@@ -1483,10 +1483,10 @@ aes_ecb_mct(char *reqfn)
         if (strncmp(buf, "KEY", 3) == 0) {
             /* Key[0] = Key */
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             keysize = j;
@@ -1500,7 +1500,7 @@ aes_ecb_mct(char *reqfn)
             }
             /* PT[0] = PT */
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof plaintext; i += 2, j++) {
@@ -1598,10 +1598,10 @@ aes_ecb_mct(char *reqfn)
             }
             /* CT[0] = CT */
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
 
@@ -1768,10 +1768,10 @@ aes_cbc_mct(char *reqfn)
         if (strncmp(buf, "KEY", 3) == 0) {
             /* Key[0] = Key */
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &key[j]);
             }
             keysize = j;
@@ -1781,7 +1781,7 @@ aes_cbc_mct(char *reqfn)
         if (strncmp(buf, "IV", 2) == 0) {
             /* IV[0] = IV */
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof iv; i += 2, j++) {
@@ -1797,7 +1797,7 @@ aes_cbc_mct(char *reqfn)
             }
             /* PT[0] = PT */
             i = 9;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof plaintext; i += 2, j++) {
@@ -1909,10 +1909,10 @@ aes_cbc_mct(char *reqfn)
             }
             /* CT[0] = CT */
             i = 10;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &ciphertext[j]);
             }
 
@@ -2535,7 +2535,7 @@ ecdsa_pkv_test(char *reqfn)
         if (strncmp(buf, "Qx", 2) == 0) {
             fputs(buf, ecdsaresp);
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&pubkey.data[1], len, &buf[i]);
@@ -2549,7 +2549,7 @@ ecdsa_pkv_test(char *reqfn)
                 continue;
             }
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&pubkey.data[1 + len], len, &buf[i]);
@@ -2667,10 +2667,10 @@ ecdsa_siggen_test(char *reqfn)
             ECPrivateKey *ecpriv;
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             msglen = j;
@@ -2857,10 +2857,10 @@ ecdsa_sigver_test(char *reqfn)
         /* Msg = ... */
         if (strncmp(buf, "Msg", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             msglen = j;
@@ -2885,7 +2885,7 @@ ecdsa_sigver_test(char *reqfn)
         if (strncmp(buf, "Qx", 2) == 0) {
             fputs(buf, ecdsaresp);
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&ecpub.publicValue.data[1], flen,
@@ -2899,7 +2899,7 @@ ecdsa_sigver_test(char *reqfn)
                 continue;
             }
             i = 2;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&ecpub.publicValue.data[1 + flen], flen,
@@ -2921,7 +2921,7 @@ ecdsa_sigver_test(char *reqfn)
         if (buf[0] == 'R') {
             fputs(buf, ecdsaresp);
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             sigvalid = from_hex_str(sig, olen, &buf[i]);
@@ -2931,7 +2931,7 @@ ecdsa_sigver_test(char *reqfn)
         if (buf[0] == 'S') {
             fputs(buf, ecdsaresp);
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             if (sigvalid) {
@@ -2963,7 +2963,7 @@ loser:
 PRBool
 isblankline(char *b)
 {
-    while (isspace(*b))
+    while (isspace((unsigned char)*b))
         b++;
     if ((*b == '\n') || (*b == 0)) {
         return PR_TRUE;
@@ -3122,7 +3122,7 @@ drbg(char *reqfn)
         if (strncmp(buf, "[PredictionResistance", 21) == 0) {
 #ifdef HANDLE_PREDICTION_RESISTANCE
             i = 21;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             if (strncmp(buf, "False", 5) == 0) {
@@ -3255,11 +3255,11 @@ drbg(char *reqfn)
             if (entropyInput) {
                 memset(entropyInput, 0, entropyInputLen);
                 i = 18;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
 
-                for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<entropyInputLen*/
+                for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<entropyInputLen*/
                     hex_to_byteval(&buf[i], &entropyInput[j]);
                 }
             }
@@ -3272,10 +3272,10 @@ drbg(char *reqfn)
             if (additionalInput) {
                 memset(additionalInput, 0, additionalInputLen);
                 i = 21;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<additionalInputLen*/
+                for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<additionalInputLen*/
                     hex_to_byteval(&buf[i], &additionalInput[j]);
                 }
             }
@@ -3287,10 +3287,10 @@ drbg(char *reqfn)
         /* Entropy input = ... */
         if (strncmp(buf, "EntropyInput", 12) == 0) {
             i = 12;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<entropyInputLen*/
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<entropyInputLen*/
                 hex_to_byteval(&buf[i], &entropyInput[j]);
             }
             fputs(buf, rngresp);
@@ -3300,10 +3300,10 @@ drbg(char *reqfn)
         /* nouce = ... */
         if (strncmp(buf, "Nonce", 5) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<nonceLen*/
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<nonceLen*/
                 hex_to_byteval(&buf[i], &nonce[j]);
             }
             fputs(buf, rngresp);
@@ -3314,10 +3314,10 @@ drbg(char *reqfn)
         if (strncmp(buf, "PersonalizationString", 21) == 0) {
             if (personalizationString) {
                 i = 21;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
-                for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<personalizationStringLen*/
+                for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<personalizationStringLen*/
                     hex_to_byteval(&buf[i], &personalizationString[j]);
                 }
             }
@@ -3330,7 +3330,7 @@ drbg(char *reqfn)
         if (strncmp(buf, "AdditionalInput", 15) == 0) {
             if (additionalInput) {
                 i = 15;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
                 for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<additionalInputLen*/
@@ -3350,10 +3350,10 @@ drbg(char *reqfn)
         /* Returned bits = ... */
         if (strncmp(buf, "ReturnedBits", 12) == 0) {
             i = 12;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) { /*j<additionalInputLen*/
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) { /*j<additionalInputLen*/
                 hex_to_byteval(&buf[i], &predictedreturn_bytes[j]);
             }
 
@@ -3452,7 +3452,7 @@ rng_vst(char *reqfn)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof Q; i += 2, j++) {
@@ -3474,7 +3474,7 @@ rng_vst(char *reqfn)
         /* b = ... */
         if (buf[0] == 'b') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             b = atoi(&buf[i]);
@@ -3487,7 +3487,7 @@ rng_vst(char *reqfn)
         /* XKey = ... */
         if (strncmp(buf, "XKey", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < b / 8; i += 2, j++) {
@@ -3499,7 +3499,7 @@ rng_vst(char *reqfn)
         /* XSeed = ... */
         if (strncmp(buf, "XSeed", 5) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < b / 8; i += 2, j++) {
@@ -3575,7 +3575,7 @@ rng_mct(char *reqfn)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof Q; i += 2, j++) {
@@ -3597,7 +3597,7 @@ rng_mct(char *reqfn)
         /* b = ... */
         if (buf[0] == 'b') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             b = atoi(&buf[i]);
@@ -3610,7 +3610,7 @@ rng_mct(char *reqfn)
         /* XKey = ... */
         if (strncmp(buf, "XKey", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < b / 8; i += 2, j++) {
@@ -3623,7 +3623,7 @@ rng_mct(char *reqfn)
         if (strncmp(buf, "XSeed", 5) == 0) {
             unsigned int k;
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < b / 8; i += 2, j++) {
@@ -3774,7 +3774,7 @@ sha_test(char *reqfn)
         if (buf[0] == '[') {
             if (strncmp(&buf[1], "L ", 1) == 0) {
                 i = 2;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
                 MDlen = atoi(&buf[i]);
@@ -3785,7 +3785,7 @@ sha_test(char *reqfn)
         /* Len = Length of the Input Message Length  ... */
         if (strncmp(buf, "Len", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             if (msg) {
@@ -3809,7 +3809,7 @@ sha_test(char *reqfn)
         /* MSG = ... */
         if (strncmp(buf, "Msg", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < msgLen; i += 2, j++) {
@@ -3833,7 +3833,7 @@ sha_test(char *reqfn)
         /* Seed = ... */
         if (strncmp(buf, "Seed", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < sizeof seed; i += 2, j++) {
@@ -3951,11 +3951,11 @@ hmac_test(char *reqfn)
     while (fgets(buf, bufSize, req) != NULL) {
         if (strncmp(buf, "Mac", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(expectedHMAC, 0, HASH_LENGTH_MAX);
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &expectedHMAC[j]);
             }
             if (memcmp(HMAC, expectedHMAC, TLen) != 0) {
@@ -3981,7 +3981,7 @@ hmac_test(char *reqfn)
         if (buf[0] == '[') {
             if (strncmp(&buf[1], "L ", 1) == 0) {
                 i = 2;
-                while (isspace(buf[i]) || buf[i] == '=') {
+                while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                     i++;
                 }
                 /* HMACLen will get reused for Tlen */
@@ -4009,7 +4009,7 @@ hmac_test(char *reqfn)
         /* KLen = Length of the Input Secret Key ... */
         if (strncmp(buf, "Klen", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyLen = atoi(&buf[i]); /* in bytes */
@@ -4019,7 +4019,7 @@ hmac_test(char *reqfn)
         /* key = the secret key for the key to MAC */
         if (strncmp(buf, "Key", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < keyLen; i += 2, j++) {
@@ -4030,7 +4030,7 @@ hmac_test(char *reqfn)
         /* TLen = Length of the calculated HMAC */
         if (strncmp(buf, "Tlen", 4) == 0) {
             i = 4;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             TLen = atoi(&buf[i]); /* in bytes */
@@ -4040,7 +4040,7 @@ hmac_test(char *reqfn)
         /* MSG = to HMAC always 128 bytes for these tests */
         if (strncmp(buf, "Msg", 3) == 0) {
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < msgLen; i += 2, j++) {
@@ -4320,7 +4320,7 @@ dsa_pqgver_test(char *reqfn)
         /* P = ... */
         if (buf[0] == 'P') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.prime.len; i += 2, j++) {
@@ -4334,7 +4334,7 @@ dsa_pqgver_test(char *reqfn)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.subPrime.len; i += 2, j++) {
@@ -4352,7 +4352,7 @@ dsa_pqgver_test(char *reqfn)
                 SECITEM_ZfreeItem(&pqg.base, PR_FALSE);
             }
             SECITEM_AllocItem(NULL, &pqg.base, pghSize);
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pqg.base.len; i += 2, j++) {
@@ -4374,10 +4374,10 @@ dsa_pqgver_test(char *reqfn)
             i = 0;
         }
         if (i) {
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &vfy.seed.data[j]);
             }
             vfy.seed.len = j;
@@ -4402,10 +4402,10 @@ dsa_pqgver_test(char *reqfn)
         if ((strncmp(buf, "pseed", 5) == 0) ||
             (strncmp(buf, "qseed", 5) == 0)) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = vfy.seed.len; isxdigit(buf[i]); i += 2, j++) {
+            for (j = vfy.seed.len; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &vfy.seed.data[j]);
             }
             vfy.seed.len = j;
@@ -4415,7 +4415,7 @@ dsa_pqgver_test(char *reqfn)
         }
         if (strncmp(buf, "index", 4) == 0) {
             i = 5;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             hex_to_byteval(&buf[i], &vfy.h.data[0]);
@@ -4482,10 +4482,10 @@ dsa_pqgver_test(char *reqfn)
             SECStatus rv, result = SECFailure;
 
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &vfy.h.data[j]);
             }
             vfy.h.len = j;
@@ -4834,10 +4834,10 @@ dsa_siggen_test(char *reqfn)
             memset(sig, 0, sizeof sig);
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             if (fips_hashBuf(hashType, hashBuf, msg, j) != SECSuccess) {
@@ -4979,7 +4979,7 @@ dsa_sigver_test(char *reqfn)
         /* P = ... */
         if (buf[0] == 'P') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.params.prime.data, 0, pubkey.params.prime.len);
@@ -4994,7 +4994,7 @@ dsa_sigver_test(char *reqfn)
         /* Q = ... */
         if (buf[0] == 'Q') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.params.subPrime.data, 0, pubkey.params.subPrime.len);
@@ -5009,7 +5009,7 @@ dsa_sigver_test(char *reqfn)
         /* G = ... */
         if (buf[0] == 'G') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.params.base.data, 0, pubkey.params.base.len);
@@ -5032,10 +5032,10 @@ dsa_sigver_test(char *reqfn)
             }
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]); i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             if (fips_hashBuf(hashType, hashBuf, msg, j) != SECSuccess) {
@@ -5051,7 +5051,7 @@ dsa_sigver_test(char *reqfn)
         /* Y = ... */
         if (buf[0] == 'Y') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             memset(pubkey.publicValue.data, 0, pubkey.params.subPrime.len);
@@ -5067,7 +5067,7 @@ dsa_sigver_test(char *reqfn)
         if (buf[0] == 'R') {
             memset(sig, 0, sizeof sig);
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pubkey.params.subPrime.len; i += 2, j++) {
@@ -5086,7 +5086,7 @@ dsa_sigver_test(char *reqfn)
             }
 
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = pubkey.params.subPrime.len;
@@ -5342,7 +5342,7 @@ rsa_siggen_test(char *reqfn)
         /* SHAAlg = ... */
         if (strncmp(buf, "SHAAlg", 6) == 0) {
             i = 6;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             /* set the SHA Algorithm */
@@ -5389,10 +5389,10 @@ rsa_siggen_test(char *reqfn)
             memset(rsa_computed_signature, 0, sizeof rsa_computed_signature);
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
-            for (j = 0; isxdigit(buf[i]) && j < sizeof(msg); i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]) && j < sizeof(msg); i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
             shaLength = fips_hashLen(shaAlg);
@@ -5519,7 +5519,7 @@ rsa_sigver_test(char *reqfn)
         /* n = ... modulus */
         if (buf[0] == 'n') {
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             keyvalid = from_hex_str(&rsaBlapiPublicKey.modulus.data[0],
@@ -5537,7 +5537,7 @@ rsa_sigver_test(char *reqfn)
         /* SHAAlg = ... */
         if (strncmp(buf, "SHAAlg", 6) == 0) {
             i = 6;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             /* set the SHA Algorithm */
@@ -5571,11 +5571,11 @@ rsa_sigver_test(char *reqfn)
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
                     i += 2;
@@ -5584,7 +5584,7 @@ rsa_sigver_test(char *reqfn)
             }
 
             /* get the exponent */
-            for (j = 0; isxdigit(buf[i]) && j < sizeof data; i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]) && j < sizeof data; i += 2, j++) {
                 hex_to_byteval(&buf[i], &data[j]);
             }
 
@@ -5613,11 +5613,11 @@ rsa_sigver_test(char *reqfn)
             memset(msg, 0, sizeof msg);
 
             i = 3;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
 
-            for (j = 0; isxdigit(buf[i]) && j < sizeof msg; i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]) && j < sizeof msg; i += 2, j++) {
                 hex_to_byteval(&buf[i], &msg[j]);
             }
 
@@ -5648,11 +5648,11 @@ rsa_sigver_test(char *reqfn)
 
             memset(signature, 0, sizeof(signature));
             i = 1;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
 
-            for (j = 0; isxdigit(buf[i]) && j < sizeof signature; i += 2, j++) {
+            for (j = 0; isxdigit((unsigned char)buf[i]) && j < sizeof signature; i += 2, j++) {
                 hex_to_byteval(&buf[i], &signature[j]);
             }
 
@@ -5853,7 +5853,7 @@ tls(char *reqfn)
         /* pre_master_secret = ... */
         if (strncmp(buf, "pre_master_secret", 17) == 0) {
             i = 17;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < pms_len; i += 2, j++) {
@@ -5865,7 +5865,7 @@ tls(char *reqfn)
         /* serverHello_random = ... */
         if (strncmp(buf, "serverHello_random", 18) == 0) {
             i = 18;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < SSL3_RANDOM_LENGTH; i += 2, j++) {
@@ -5877,7 +5877,7 @@ tls(char *reqfn)
         /* clientHello_random = ... */
         if (strncmp(buf, "clientHello_random", 18) == 0) {
             i = 18;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < SSL3_RANDOM_LENGTH; i += 2, j++) {
@@ -5889,7 +5889,7 @@ tls(char *reqfn)
         /* server_random = ... */
         if (strncmp(buf, "server_random", 13) == 0) {
             i = 13;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < SSL3_RANDOM_LENGTH; i += 2, j++) {
@@ -5905,7 +5905,7 @@ tls(char *reqfn)
             CK_OBJECT_HANDLE master_handle;
             CK_OBJECT_HANDLE fake_handle;
             i = 13;
-            while (isspace(buf[i]) || buf[i] == '=') {
+            while (isspace((unsigned char)buf[i]) || buf[i] == '=') {
                 i++;
             }
             for (j = 0; j < SSL3_RANDOM_LENGTH; i += 2, j++) {

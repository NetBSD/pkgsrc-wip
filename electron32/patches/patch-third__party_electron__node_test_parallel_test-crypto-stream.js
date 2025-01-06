$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-stream.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-stream.js
@@ -76,10 +76,10 @@ cipher.pipe(decipher)
     library: 'Provider routines',
     reason: 'bad decrypt',
   } : {
-    message: /bad decrypt/,
-    function: 'EVP_DecryptFinal_ex',
-    library: 'digital envelope routines',
-    reason: 'bad decrypt',
+    message: /bad decrypt|BAD_DECRYPT/,
+    function: /EVP_DecryptFinal_ex|OPENSSL_internal/,
+    library: /digital envelope routines|Cipher functions/,
+    reason: /bad decrypt|BAD_DECRYPT/,
   }));
 
 cipher.end('Papaya!');  // Should not cause an unhandled exception.

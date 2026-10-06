$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-cipher-decipher.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-cipher-decipher.js
@@ -22,7 +22,7 @@ common.expectWarning({
 function testCipher1(key) {
   // Test encryption and decryption
   const plaintext = 'Keep this a secret? No! Tell everyone about node.js!';
-  const cipher = crypto.createCipher('aes192', key);
+  const cipher = crypto.createCipher('aes-192-cbc', key);
 
   // Encrypt plaintext which is in utf8 format
   // to a ciphertext which will be in hex
@@ -30,7 +30,7 @@ function testCipher1(key) {
   // Only use binary or hex, not base64.
   ciph += cipher.final('hex');
 
-  const decipher = crypto.createDecipher('aes192', key);
+  const decipher = crypto.createDecipher('aes-192-cbc', key);
   let txt = decipher.update(ciph, 'hex', 'utf8');
   txt += decipher.final('utf8');
 
@@ -40,11 +40,11 @@ function testCipher1(key) {
   // NB: In real life, it's not guaranteed that you can get all of it
   // in a single read() like this.  But in this case, we know it's
   // quite small, so there's no harm.
-  const cStream = crypto.createCipher('aes192', key);
+  const cStream = crypto.createCipher('aes-192-cbc', key);
   cStream.end(plaintext);
   ciph = cStream.read();
 
-  const dStream = crypto.createDecipher('aes192', key);
+  const dStream = crypto.createDecipher('aes-192-cbc', key);
   dStream.end(ciph);
   txt = dStream.read().toString('utf8');
 
@@ -59,14 +59,14 @@ function testCipher2(key) {
       '32|RmVZZkFUVmpRRkp0TmJaUm56ZU9qcnJkaXNNWVNpTTU*|iXmckfRWZBGWWELw' +
       'eCBsThSsfUHLeRe0KCsK8ooHgxie0zOINpXxfZi/oNG7uq9JWFVCk70gfzQH8ZUJ' +
       'jAfaFg**';
-  const cipher = crypto.createCipher('aes256', key);
+  const cipher = crypto.createCipher('aes-256-cbc', key);
 
   // Encrypt plaintext which is in utf8 format to a ciphertext which will be in
   // Base64.
   let ciph = cipher.update(plaintext, 'utf8', 'base64');
   ciph += cipher.final('base64');
 
-  const decipher = crypto.createDecipher('aes256', key);
+  const decipher = crypto.createDecipher('aes-256-cbc', key);
   let txt = decipher.update(ciph, 'base64', 'utf8');
   txt += decipher.final('utf8');
 
@@ -170,7 +170,7 @@ testCipher2(Buffer.from('0123456789abcde
 // Regression test for https://github.com/nodejs/node-v0.x-archive/issues/5482:
 // string to Cipher#update() should not assert.
 {
-  const c = crypto.createCipher('aes192', '0123456789abcdef');
+  const c = crypto.createCipher('aes-192-cbc', '0123456789abcdef');
   c.update('update');
   c.final();
 }
@@ -178,15 +178,15 @@ testCipher2(Buffer.from('0123456789abcde
 // https://github.com/nodejs/node-v0.x-archive/issues/5655 regression tests,
 // 'utf-8' and 'utf8' are identical.
 {
-  let c = crypto.createCipher('aes192', '0123456789abcdef');
+  let c = crypto.createCipher('aes-192-cbc', '0123456789abcdef');
   c.update('update', '');  // Defaults to "utf8".
   c.final('utf-8');  // Should not throw.
 
-  c = crypto.createCipher('aes192', '0123456789abcdef');
+  c = crypto.createCipher('aes-192-cbc', '0123456789abcdef');
   c.update('update', 'utf8');
   c.final('utf-8');  // Should not throw.
 
-  c = crypto.createCipher('aes192', '0123456789abcdef');
+  c = crypto.createCipher('aes-192-cbc', '0123456789abcdef');
   c.update('update', 'utf-8');
   c.final('utf8');  // Should not throw.
 }
@@ -195,23 +195,23 @@ testCipher2(Buffer.from('0123456789abcde
 {
   const key = '0123456789abcdef';
   const plaintext = 'Top secret!!!';
-  const c = crypto.createCipher('aes192', key);
+  const c = crypto.createCipher('aes-192-cbc', key);
   let ciph = c.update(plaintext, 'utf16le', 'base64');
   ciph += c.final('base64');
 
-  let decipher = crypto.createDecipher('aes192', key);
+  let decipher = crypto.createDecipher('aes-192-cbc', key);
 
   let txt;
   txt = decipher.update(ciph, 'base64', 'ucs2');
   txt += decipher.final('ucs2');
   assert.strictEqual(txt, plaintext);
 
-  decipher = crypto.createDecipher('aes192', key);
+  decipher = crypto.createDecipher('aes-192-cbc', key);
   txt = decipher.update(ciph, 'base64', 'ucs-2');
   txt += decipher.final('ucs-2');
   assert.strictEqual(txt, plaintext);
 
-  decipher = crypto.createDecipher('aes192', key);
+  decipher = crypto.createDecipher('aes-192-cbc', key);
   txt = decipher.update(ciph, 'base64', 'utf-16le');
   txt += decipher.final('utf-16le');
   assert.strictEqual(txt, plaintext);

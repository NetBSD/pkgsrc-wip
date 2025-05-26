$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-authenticated.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-authenticated.js
@@ -48,7 +48,9 @@ const errMessages = {
 const ciphers = crypto.getCiphers();
 
 const expectedWarnings = common.hasFipsCrypto ?
-  [] : [
+  [] : !ciphers.includes('aes-192-ccm') ? [
+    ['Use Cipheriv for counter mode of aes-192-gcm'],
+  ] : [
     ['Use Cipheriv for counter mode of aes-192-gcm'],
     ['Use Cipheriv for counter mode of aes-192-ccm'],
     ['Use Cipheriv for counter mode of aes-192-ccm'],
@@ -315,7 +317,9 @@ for (const test of TEST_CASES) {
 
 // Test that create(De|C)ipher(iv)? throws if the mode is CCM and an invalid
 // authentication tag length has been specified.
-{
+if (!ciphers.includes('aes-256-ccm')) {
+  common.printSkipMessage(`unsupported aes-256-ccm test`);
+} else {
   for (const authTagLength of [-1, true, false, NaN, 5.5]) {
     assert.throws(() => {
       crypto.createCipheriv('aes-256-ccm',
@@ -403,6 +407,10 @@ for (const test of TEST_CASES) {
 // authentication tag has been specified.
 {
   for (const mode of ['ccm', 'ocb']) {
+    if (!ciphers.includes(`aes-256-${mode}`)) {
+      common.printSkipMessage(`unsupported aes-256-${mode} test`);
+      continue;
+    }
     assert.throws(() => {
       crypto.createCipheriv(`aes-256-${mode}`,
                             'FxLKsqdmv0E9xrQhp0b1ZgI0K7JFZJM8',
@@ -437,7 +445,9 @@ for (const test of TEST_CASES) {
 }
 
 // Test that setAAD throws if an invalid plaintext length has been specified.
-{
+if (!ciphers.includes('aes-256-ccm')) {
+  common.printSkipMessage(`unsupported aes-256-ccm test`);
+} else {
   const cipher = crypto.createCipheriv('aes-256-ccm',
                                        'FxLKsqdmv0E9xrQhp0b1ZgI0K7JFZJM8',
                                        'qkuZpJWCewa6S',
@@ -458,7 +468,9 @@ for (const test of TEST_CASES) {
 }
 
 // Test that setAAD and update throw if the plaintext is too long.
-{
+if (!ciphers.includes('aes-256-ccm')) {
+  common.printSkipMessage(`unsupported aes-256-ccm test`);
+} else {
   for (const ivLength of [13, 12]) {
     const maxMessageSize = (1 << (8 * (15 - ivLength))) - 1;
     const key = 'FxLKsqdmv0E9xrQhp0b1ZgI0K7JFZJM8';
@@ -489,7 +501,9 @@ for (const test of TEST_CASES) {
 
 // Test that setAAD throws if the mode is CCM and the plaintext length has not
 // been specified.
-{
+if (!ciphers.includes('aes-256-ccm')) {
+  common.printSkipMessage(`unsupported aes-256-ccm test`);
+} else {
   assert.throws(() => {
     const cipher = crypto.createCipheriv('aes-256-ccm',
                                          'FxLKsqdmv0E9xrQhp0b1ZgI0K7JFZJM8',
@@ -514,7 +528,9 @@ for (const test of TEST_CASES) {
 }
 
 // Test that final() throws in CCM mode when no authentication tag is provided.
-{
+if (!ciphers.includes('aes-128-ccm')) {
+  common.printSkipMessage(`unsupported aes-256-ccm test`);
+} else {
   if (!common.hasFipsCrypto) {
     const key = Buffer.from('1ed2233fa2223ef5d7df08546049406c', 'hex');
     const iv = Buffer.from('7305220bca40d4c90e1791e9', 'hex');
@@ -546,7 +562,9 @@ for (const test of TEST_CASES) {
 }
 
 // Test that an IV length of 11 does not overflow max_message_size_.
-{
+if (!ciphers.includes('aes-128-ccm')) {
+  common.printSkipMessage(`unsupported aes-128-ccm test`);
+} else {
   const key = 'x'.repeat(16);
   const iv = Buffer.from('112233445566778899aabb', 'hex');
   const options = { authTagLength: 8 };
@@ -563,6 +581,10 @@ for (const test of TEST_CASES) {
   const iv = Buffer.from('0123456789ab', 'utf8');
 
   for (const mode of ['gcm', 'ocb']) {
+    if (!ciphers.includes(`aes-128-${mode}`)) {
+      common.printSkipMessage(`unsupported aes-128-${mode} test`);
+      continue;
+    }
     for (const authTagLength of mode === 'gcm' ? [undefined, 8] : [8]) {
       const cipher = crypto.createCipheriv(`aes-128-${mode}`, key, iv, {
         authTagLength
@@ -597,6 +619,10 @@ for (const test of TEST_CASES) {
   const opts = { authTagLength: 8 };
 
   for (const mode of ['gcm', 'ccm', 'ocb']) {
+    if (!ciphers.includes(`aes-128-${mode}`)) {
+      common.printSkipMessage(`unsupported aes-128-${mode} test`);
+      continue;
+    }
     const cipher = crypto.createCipheriv(`aes-128-${mode}`, key, iv, opts);
     const ciphertext = Buffer.concat([cipher.update(plain), cipher.final()]);
     const tag = cipher.getAuthTag();
@@ -619,7 +645,9 @@ for (const test of TEST_CASES) {
 // Test chacha20-poly1305 rejects invalid IV lengths of 13, 14, 15, and 16 (a
 // length of 17 or greater was already rejected).
 // - https://www.openssl.org/news/secadv/20190306.txt
-{
+if (!ciphers.includes('chacha20-poly1305')) {
+  common.printSkipMessage(`unsupported chacha20-poly1305 test`);
+} else {
   // Valid extracted from TEST_CASES, check that it detects IV tampering.
   const valid = {
     algo: 'chacha20-poly1305',
@@ -664,6 +692,9 @@ for (const test of TEST_CASES) {
 
 {
   // CCM cipher without data should not crash, see https://github.com/nodejs/node/issues/38035.
+  common.printSkipMessage(`unsupported aes-128-ccm test`);
+  return;
+
   const algo = 'aes-128-ccm';
   const key = Buffer.alloc(16);
   const iv = Buffer.alloc(12);

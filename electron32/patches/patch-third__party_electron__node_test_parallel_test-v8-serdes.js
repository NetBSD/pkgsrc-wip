$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-v8-serdes.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-v8-serdes.js
@@ -163,11 +163,11 @@ const hostObject = new (internalBinding(
 
 {
   // Test that an old serialized value can still be deserialized.
-  const buf = Buffer.from('ff0d6f2203666f6f5e007b01', 'hex');
+  const buf = Buffer.from('ff0f6f2203666f6f5e007b01', 'hex');
 
   const des = new v8.DefaultDeserializer(buf);
   des.readHeader();
-  assert.strictEqual(des.getWireFormatVersion(), 0x0d);
+  assert.strictEqual(des.getWireFormatVersion(), 0x0f);
 
   const value = des.readValue();
   assert.strictEqual(value, value.foo);
@@ -202,7 +202,7 @@ const hostObject = new (internalBinding(
 {
   // Unaligned Uint16Array read, with padding in the underlying array buffer.
   let buf = Buffer.alloc(32 + 9);
-  buf.write('ff0d5c0404addeefbe', 32, 'hex');
+  buf.write('ff0e5c0404addeefbe', 32, 'hex');
   buf = buf.slice(32);
 
   const expectedResult = os.endianness() === 'LE' ?

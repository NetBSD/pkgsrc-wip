$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/nan/test/js/accessors-test.js.orig	2023-09-12 12:23:33.000000000 +0000
+++ third_party/nan/test/js/accessors-test.js
@@ -11,7 +11,7 @@ const test     = require('tap').test
     , bindings = require('bindings')({ module_root: testRoot, bindings: 'accessors' });
 
 test('accessors', function (t) {
-  t.plan(7)
+  t.plan(6)
   var settergetter = bindings.create()
   t.equal(settergetter.prop1, 'this is property 1')
   t.ok(settergetter.prop2 === '')
@@ -28,5 +28,4 @@ test('accessors', function (t) {
   t.equal(derived.prop1, 'this is property 1')
   derived.prop2 = 'setting a new value'
   t.equal(derived.prop2, 'setting a new value')
-  t.equal(settergetter.prop2, 'setting a new value')
 })

$NetBSD$

* Let pkgsrc to build rust package

--- deps/extension/extension.gyp.orig	2026-11-05 18:23:25.627547058 +0000
+++ deps/extension/extension.gyp
@@ -1,5 +1,8 @@
 {
   'variables': {
+    'rust_arch%': '',
+    'rust_prefix%': 'lib',
+    'rust_ext%': 'a',
     'conditions': [
       ['OS == "mac" and target_arch == "x64"', {
         'rust_arch': 'x86_64-apple-darwin',
@@ -66,17 +69,15 @@
       'inputs': [],
       'outputs': [
         'target/signal-tokenizer.h',
-        'target/<(rust_arch)/release/<(rust_prefix)signal_sqlcipher_extension.<(rust_ext)',
+        'target/release/<(rust_prefix)signal_sqlcipher_extension.<(rust_ext)',
       ],
       'action': [
-        'node',
-        'cargo-wrap.js',
-        'target/<(rust_arch)',
+        'true',
       ],
     }],
     'copies': [{
       'files': [
-        'target/<(rust_arch)/release/<(rust_prefix)signal_sqlcipher_extension.<(rust_ext)',
+        'target/release/<(rust_prefix)signal_sqlcipher_extension.<(rust_ext)',
       ],
       'destination': '<(SHARED_INTERMEDIATE_DIR)',
     }],

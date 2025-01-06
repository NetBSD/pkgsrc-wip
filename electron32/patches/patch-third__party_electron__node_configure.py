$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/configure.py.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/configure.py
@@ -1585,6 +1585,7 @@ def configure_library(lib, output, pkgna
 
 
 def configure_v8(o):
+  o['variables']['using_electron_config_gypi'] = 1
   o['variables']['v8_enable_webassembly'] = 0 if options.v8_lite_mode else 1
   o['variables']['v8_enable_javascript_promise_hooks'] = 1
   o['variables']['v8_enable_lite_mode'] = 1 if options.v8_lite_mode else 0

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/tools/install.py.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/tools/install.py
@@ -270,6 +270,7 @@ def headers(options, action):
       'include/v8-forward.h',
       'include/v8-function-callback.h',
       'include/v8-function.h',
+      'include/v8-handle-base.h',
       'include/v8-initialization.h',
       'include/v8-internal.h',
       'include/v8-isolate.h',
@@ -290,6 +291,8 @@ def headers(options, action):
       'include/v8-promise.h',
       'include/v8-proxy.h',
       'include/v8-regexp.h',
+      "include/v8-sandbox.h",
+      "include/v8-source-location.h",
       'include/v8-script.h',
       'include/v8-snapshot.h',
       'include/v8-statistics.h',
@@ -396,7 +399,7 @@ def parse_options(args):
   parser.add_argument('--build-dir', help='the location of built binaries',
                       default='out/Release')
   parser.add_argument('--v8-dir', help='the location of V8',
-                      default='deps/v8')
+                      default='../../v8')
   parser.add_argument('--config-gypi-path', help='the location of config.gypi',
                       default='config.gypi')
   parser.add_argument('--is-win', help='build for Windows target',

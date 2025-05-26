$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/node.gypi.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/node.gypi
@@ -63,10 +63,6 @@
         'FD_SETSIZE=1024',
         # we need to use node's preferred "win32" rather than gyp's preferred "win"
         'NODE_PLATFORM="win32"',
-        # Stop <windows.h> from defining macros that conflict with
-        # std::min() and std::max().  We don't use <windows.h> (much)
-        # but we still inherit it from uv.h.
-        'NOMINMAX',
         '_UNICODE=1',
       ],
       'msvs_precompiled_header': 'tools/msvs/pch/node_pch.h',

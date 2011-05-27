$NetBSD: patch-third__party_WebKit_Source_WebCore_WebCore.gyp_WebCore.gyp,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- third_party/WebKit/Source/WebCore/WebCore.gyp/WebCore.gyp.orig	2011-05-24 08:03:25.000000000 +0000
+++ third_party/WebKit/Source/WebCore/WebCore.gyp/WebCore.gyp
@@ -992,7 +992,7 @@
             '<(chromium_src_dir)/gpu/gpu.gyp:gles2_c_lib',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '<(chromium_src_dir)/build/linux/system.gyp:fontconfig',
             '<(chromium_src_dir)/build/linux/system.gyp:gtk',
@@ -1197,7 +1197,7 @@
         ['include', 'thirdparty/glu/libtess/'],
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'sources/': [
             # Cherry-pick files excluded by the broader regular expressions above.
             ['include', 'platform/chromium/KeyCodeConversionGtk\\.cpp$'],
@@ -1310,7 +1310,7 @@
             ['exclude', 'platform/chromium/DragImageChromiumSkia\\.cpp$'],
           ],
         }],
-        ['OS!="linux" and OS!="freebsd"', {
+        ['OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd"', {
           'sources/': [
             ['exclude', '(Gtk|Linux)\\.cpp$'],
             ['exclude', 'Harfbuzz[^/]+\\.(cpp|h)$'],
@@ -1385,12 +1385,12 @@
             ['exclude', 'rendering/RenderThemeChromiumSkia\\.cpp$'],
           ],
         }],
-        ['(OS=="linux" or OS=="freebsd" or OS=="openbsd") and gcc_version==42', {
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and gcc_version==42', {
           # Due to a bug in gcc 4.2.1 (the current version on hardy), we get
           # warnings about uninitialized this.
           'cflags': ['-Wno-uninitialized'],
         }],
-        ['OS!="linux" and OS!="freebsd"', {
+        ['OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd"', {
           'sources/': [
             ['exclude', '(Gtk|Linux)\\.cpp$'],
           ],
@@ -1529,12 +1529,12 @@
             ['include', '/TransparencyWin\\.cpp$'],
           ],
         }],
-        ['(OS=="linux" or OS=="freebsd" or OS=="openbsd") and gcc_version==42', {
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and gcc_version==42', {
           # Due to a bug in gcc 4.2.1 (the current version on hardy), we get
           # warnings about uninitialized this.
           'cflags': ['-Wno-uninitialized'],
         }],
-        ['OS!="linux" and OS!="freebsd"', {
+        ['OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd"', {
           'sources/': [
             ['exclude', '(Gtk|Linux)\\.cpp$'],
           ],

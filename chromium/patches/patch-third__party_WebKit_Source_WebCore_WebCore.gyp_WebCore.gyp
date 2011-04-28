$NetBSD: patch-third__party_WebKit_Source_WebCore_WebCore.gyp_WebCore.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/WebCore.gyp/WebCore.gyp.orig	2011-04-13 08:12:31.000000000 +0000
+++ third_party/WebKit/Source/WebCore/WebCore.gyp/WebCore.gyp
@@ -950,7 +950,7 @@
             '<(chromium_src_dir)/gpu/gpu.gyp:gles2_c_lib',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '<(chromium_src_dir)/build/linux/system.gyp:fontconfig',
             '<(chromium_src_dir)/build/linux/system.gyp:gtk',
@@ -1122,7 +1122,7 @@
         ['include', 'thirdparty/glu/libtess/'],
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'sources/': [
             # Cherry-pick files excluded by the broader regular expressions above.
             ['include', 'platform/chromium/KeyCodeConversionGtk\\.cpp$'],
@@ -1240,7 +1240,7 @@
             ['exclude', 'platform/chromium/DragImageChromiumSkia\\.cpp$'],
           ],
         }],
-        ['OS!="linux" and OS!="freebsd"', {
+        ['OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd"', {
           'sources/': [
             ['exclude', '(Gtk|Linux)\\.cpp$'],
             ['exclude', 'Harfbuzz[^/]+\\.(cpp|h)$'],
@@ -1399,12 +1399,12 @@
             ['exclude', 'rendering/RenderThemeChromiumSkia\\.cpp$'],
           ],
         }],
-        ['(OS=="linux" or OS=="freebsd" or OS=="openbsd") and gcc_version==42', {
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and gcc_version==42', {
           # Due to a bug in gcc 4.2.1 (the current version on hardy), we get
           # warnings about uninitialized this.7.
           'cflags': ['-Wno-uninitialized'],
         }],
-        ['OS!="linux" and OS!="freebsd"', {
+        ['OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd"', {
           'sources/': [
             ['exclude', '(Gtk|Linux)\\.cpp$'],
           ],

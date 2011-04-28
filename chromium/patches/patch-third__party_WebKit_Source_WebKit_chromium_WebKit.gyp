$NetBSD: patch-third__party_WebKit_Source_WebKit_chromium_WebKit.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebKit/chromium/WebKit.gyp.orig	2011-04-13 08:12:10.000000000 +0000
+++ third_party/WebKit/Source/WebKit/chromium/WebKit.gyp
@@ -618,7 +618,7 @@
                 }, {
                     'type': '<(webkit_target_type)'
                 }],
-                ['OS=="linux" or OS=="freebsd"', {
+                ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
                     'dependencies': [
                         '<(chromium_src_dir)/build/linux/system.gyp:fontconfig',
                         '<(chromium_src_dir)/build/linux/system.gyp:gtk',
@@ -824,7 +824,7 @@
                                 'tests/DragImageTest.cpp',
                             ],
                         }],
-                        ['OS=="linux" or OS=="freebsd"', {
+                        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
                             'sources': [
                                 'tests/WebInputEventFactoryTestGtk.cpp',
                             ],
@@ -994,7 +994,7 @@
                         ['exclude', 'Mac\\.cpp$'],
                     ],
                 }],
-                ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+                ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
                     'dependencies': [
                         '<(chromium_src_dir)/build/linux/system.gyp:fontconfig',
                         '<(chromium_src_dir)/build/linux/system.gyp:gtk',
@@ -1055,7 +1055,7 @@
                         'INFOPLIST_FILE': '../../../Tools/DumpRenderTree/TestNetscapePlugIn/mac/Info.plist',
                     },
                 }],
-                ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+                ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
                     'cflags': [
                         '-fvisibility=default',
                     ],
@@ -1095,7 +1095,7 @@
                         'files': ['<(PRODUCT_DIR)/TestNetscapePlugIn.plugin/'],
                     }],
                 }],
-                ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+                ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
                     'copies': [{
                         'destination': '<(PRODUCT_DIR)/plugins',
                         'files': ['<(PRODUCT_DIR)/libTestNetscapePlugIn.so'],

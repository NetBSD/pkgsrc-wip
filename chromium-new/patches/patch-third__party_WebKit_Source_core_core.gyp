$NetBSD$

--- third_party/WebKit/Source/core/core.gyp.orig	2016-06-24 01:02:44.000000000 +0000
+++ third_party/WebKit/Source/core/core.gyp
@@ -372,7 +372,7 @@
             'layout/LayoutThemeMac.mm',
           ],
         }],
-        ['OS != "linux"', {
+        ['OS != "linux" and os_bsd != 1', {
           'sources!': [
             'layout/LayoutThemeLinux.cpp',
             'layout/LayoutThemeLinux.h',
@@ -644,7 +644,7 @@
                 'layout/LayoutThemeMac.mm',
               ],
             }],
-            ['OS != "linux"', {
+            ['OS != "linux" and OS != "openbsd" and OS != "freebsd"', {
               'sources!': [
                 'layout/LayoutThemeLinux.cpp',
                 'layout/LayoutThemeLinux.h',

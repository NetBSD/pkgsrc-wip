$NetBSD$

--- chrome/chrome_browser_ui.gypi.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/chrome_browser_ui.gypi
@@ -3097,7 +3097,7 @@
             }],
           ],
         }],
-        ['use_aura==1 and chromeos==0 and use_ozone==0 and OS=="linux"', {
+        ['use_aura==1 and chromeos==0 and use_ozone==0 and (OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd")', {
           'dependencies': [
             # gtk2 is the only component that can interact with gtk2 in our new
             # world.
@@ -3282,7 +3282,7 @@
           ],
           'sources': [ '<@(chrome_browser_ui_desktop_linux_sources)' ],
         }],
-        ['OS=="linux"', {  # Both desktop Linux and ChromeOS.
+        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd"', {  # Both desktop Linux and ChromeOS.
           'sources': [ '<@(chrome_browser_ui_linux_sources)' ],
           'conditions': [
             ['use_aura==1', {

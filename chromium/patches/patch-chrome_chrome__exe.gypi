$NetBSD: patch-chrome_chrome__exe.gypi,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/chrome_exe.gypi.orig	2011-04-13 08:01:59.000000000 +0000
+++ chrome/chrome_exe.gypi
@@ -144,7 +144,7 @@
         'use_system_xdg_utils%': 0,
       },
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'actions': [
             {
               'action_name': 'manpage',

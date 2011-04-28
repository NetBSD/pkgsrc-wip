$NetBSD: patch-third__party_libxslt_libxslt.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/libxslt/libxslt.gyp.orig	2011-04-13 08:01:22.000000000 +0000
+++ third_party/libxslt/libxslt.gyp
@@ -5,7 +5,7 @@
 {
   'variables': {
     'conditions': [
-      ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
         'os_include': 'linux'
       }],
       ['OS=="mac"', {'os_include': 'mac'}],
@@ -21,7 +21,7 @@
     {
       'target_name': 'libxslt',
       'conditions': [
-        ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris") '
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris") '
          'and use_system_libxml', {
           'type': 'settings',
           'direct_dependent_settings': {

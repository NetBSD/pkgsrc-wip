$NetBSD$

--- chrome/common/extensions/api/schemas.gypi.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/common/extensions/api/schemas.gypi
@@ -184,7 +184,7 @@
         ],
       }, { # chromeos==0
         'conditions': [
-          ['OS=="linux" or OS=="win"', {
+          ['OS=="linux" or OS=="win" or os_bsd==1', {
             'schema_files': [
               '<@(input_ime_schema_file)',
             ],

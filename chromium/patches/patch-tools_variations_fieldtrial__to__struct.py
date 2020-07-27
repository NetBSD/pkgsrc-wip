$NetBSD$

--- tools/variations/fieldtrial_to_struct.py.orig	2020-07-15 18:56:33.000000000 +0000
+++ tools/variations/fieldtrial_to_struct.py
@@ -40,6 +40,9 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'freebsd',
+    'openbsd',
+    'netbsd',
 ]
 
 _form_factors = [

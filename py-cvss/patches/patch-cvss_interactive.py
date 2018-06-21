$NetBSD$

Gracefully handle possible ^D and treat it like a ^C.

--- cvss/interactive.py.orig	2018-06-21 08:24:26.154082541 +0000
+++ cvss/interactive.py
@@ -95,7 +95,10 @@ def ask_interactively(version=3, all_met
         while True:
             print(METRICS_ABBREVIATIONS[metric] + ':', end=' ')
             print('/'.join(values), end=' ')
-            input_value = string_input().upper()
+            try:
+                input_value = string_input().upper()
+            except EOFError:
+                raise KeyboardInterrupt('EOF')
             if not input_value:
                 if version == 2:
                     input_value = 'ND'

$NetBSD$

--- setup.py.orig	2020-07-20 15:51:02.000000000 +0000
+++ setup.py
@@ -400,7 +400,7 @@ class EggInfo(egg_info):
         try:
             with open(os.devnull, 'w') as devnull:
                 subprocess.check_call(
-                    ['python3', '-m', 'pip', 'show', 'projectq'],
+                    ['python'+sys.version[0:3], '-m', 'pip', 'show', 'projectq'],
                     stdout=devnull,
                     stderr=devnull)
 

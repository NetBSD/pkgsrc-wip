$NetBSD$

--- stemming/porter.py.orig	2010-02-08 23:06:43.000000000 +0000
+++ stemming/porter.py
@@ -173,7 +173,7 @@ def stem(w):
     return w
 
 if __name__ == '__main__':
-    print stem("fundamentally")
+    print(stem("fundamentally"))
     
     
     

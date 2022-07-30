$NetBSD$

Alter test to not run forever

--- tests/vectortest.py.orig	2022-07-30 20:39:36.187004151 +0000
+++ tests/vectortest.py
@@ -236,4 +236,4 @@ message.
         test_all(n,dim)

 if __name__ == "__main__":
-    test(None)
+    test(10)

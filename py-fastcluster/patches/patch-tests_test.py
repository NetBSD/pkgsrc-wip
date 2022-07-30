$NetBSD$

Alter test to not run forever

--- tests/test.py.orig	2022-02-27 10:25:41.000000000 +0000
+++ tests/test.py
@@ -159,4 +159,4 @@ message.
         test_all(D)

 if __name__ == "__main__":
-    test(None)
+    test(10)

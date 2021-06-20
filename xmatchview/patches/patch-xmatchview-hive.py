$NetBSD$

Do not return an error after successful completion.

See https://github.com/bcgsc/xmatchview/issues/12.

--- xmatchview-hive.py.orig	2021-06-20 00:25:31.000000000 +0000
+++ xmatchview-hive.py
@@ -1047,6 +1047,5 @@ def main():
 #Main Call
 
 main()
-sys.exit(1)
 
 

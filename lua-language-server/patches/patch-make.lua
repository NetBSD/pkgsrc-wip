$NetBSD: patch-make.lua,v 1.1 2023/03/29 20:27:09 nikita Exp $

Do not generate directories with spaces in the file names.

--- make.lua.orig	2023-03-23 07:23:30.000000000 +0100
+++ make.lua	2023-03-29 22:59:59.816110949 +0200
@@ -117,5 +117,5 @@
 }
 
 lm:default {
-    "unit-test",
+    "all",
 }

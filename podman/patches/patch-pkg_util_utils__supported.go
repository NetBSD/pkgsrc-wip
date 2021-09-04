$NetBSD$

--- pkg/util/utils_supported.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ pkg/util/utils_supported.go
@@ -1,4 +1,4 @@
-// +build linux darwin
+// +build !windows
 
 package util
 

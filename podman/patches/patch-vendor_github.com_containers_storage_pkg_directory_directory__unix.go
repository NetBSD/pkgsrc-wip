$NetBSD$

--- vendor/github.com/containers/storage/pkg/directory/directory_unix.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ vendor/github.com/containers/storage/pkg/directory/directory_unix.go
@@ -1,4 +1,4 @@
-// +build linux darwin freebsd solaris
+// +build !windows
 
 package directory
 

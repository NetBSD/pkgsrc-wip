$NetBSD$

--- vendor/github.com/containers/storage/pkg/homedir/homedir_others.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ vendor/github.com/containers/storage/pkg/homedir/homedir_others.go
@@ -1,4 +1,4 @@
-// +build !linux,!darwin,!freebsd
+// +build !linux,!darwin,!freebsd,!netbsd
 
 package homedir
 

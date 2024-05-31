$NetBSD$

--- vendor/github.com/containers/storage/pkg/homedir/homedir_others.go.orig	2024-05-28 22:08:53.504670587 +0000
+++ vendor/github.com/containers/storage/pkg/homedir/homedir_others.go
@@ -1,5 +1,5 @@
-//go:build !linux && !darwin && !freebsd && !windows
-// +build !linux,!darwin,!freebsd,!windows
+//go:build !linux && !darwin && !freebsd && !netbsd && !windows
+// +build !linux,!darwin,!freebsd,!netbsd,!windows
 
 package homedir
 

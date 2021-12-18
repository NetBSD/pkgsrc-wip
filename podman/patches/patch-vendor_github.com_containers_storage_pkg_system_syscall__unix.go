$NetBSD$

--- vendor/github.com/containers/storage/pkg/system/syscall_unix.go.orig	2021-12-08 18:41:11.000000000 +0000
+++ vendor/github.com/containers/storage/pkg/system/syscall_unix.go
@@ -1,4 +1,4 @@
-// +build linux freebsd darwin
+// +build linux freebsd darwin netbsd
 
 package system
 

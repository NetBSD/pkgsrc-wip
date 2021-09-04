$NetBSD$

--- vendor/github.com/containers/storage/drivers/chroot_unix.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ vendor/github.com/containers/storage/drivers/chroot_unix.go
@@ -1,4 +1,4 @@
-// +build linux darwin freebsd solaris
+// +build !windows
 
 package graphdriver
 

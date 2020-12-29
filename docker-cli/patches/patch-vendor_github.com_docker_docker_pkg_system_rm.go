$NetBSD$

Fix build for NetBSD.

github.com/sys/mount needs to be ported on NetBSD.

--- vendor/github.com/docker/docker/pkg/system/rm.go.orig	2020-12-15 02:27:14.000000000 +0000
+++ vendor/github.com/docker/docker/pkg/system/rm.go
@@ -1,4 +1,4 @@
-// +build !darwin,!windows
+// +build !darwin,!netbsd,!windows
 
 package system // import "github.com/docker/docker/pkg/system"
 

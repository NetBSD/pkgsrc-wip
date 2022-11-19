$NetBSD$

Fix build for NetBSD.

github.com/moby/sys/mount needs to be ported on NetBSD.

--- vendor/github.com/docker/docker/pkg/system/rm.go.orig	2022-10-25 17:53:02.000000000 +0000
+++ vendor/github.com/docker/docker/pkg/system/rm.go
@@ -1,5 +1,5 @@
-//go:build !darwin && !windows
-// +build !darwin,!windows
+//go:build !darwin && !netbsd && !windows
+// +build !darwin,!netbsd,!windows
 
 package system // import "github.com/docker/docker/pkg/system"
 

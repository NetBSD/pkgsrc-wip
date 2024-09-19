$NetBSD$

Fix build for NetBSD.

github.com/moby/sys/mount needs to be ported on NetBSD.

--- ../github.com/docker/docker@v20.10.5+incompatible/pkg/system/rm.go.orig	1979-11-29 23:00:00.000000000 +0000
+++ ../github.com/docker/docker@v20.10.5+incompatible/pkg/system/rm.go
@@ -1,4 +1,4 @@
-// +build !darwin,!windows
+// +build !darwin,!netbsd,!windows
 
 package system // import "github.com/docker/docker/pkg/system"
 

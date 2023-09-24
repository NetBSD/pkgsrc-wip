$NetBSD$

Add support for NetBSD.

--- pkg/container/docker_volume.go.orig	2023-09-23 11:36:33.000000000 +0000
+++ pkg/container/docker_volume.go
@@ -1,4 +1,4 @@
-//go:build !(WITHOUT_DOCKER || !(linux || darwin || windows))
+//go:build !(WITHOUT_DOCKER || !(linux || darwin || windows || netbsd))
 
 package container
 

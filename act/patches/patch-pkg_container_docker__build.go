$NetBSD$

Add support for NetBSD.

Shared via <https://github.com/nektos/act/pull/2023>.

--- pkg/container/docker_build.go.orig	2023-09-23 11:36:33.000000000 +0000
+++ pkg/container/docker_build.go
@@ -1,4 +1,4 @@
-//go:build !(WITHOUT_DOCKER || !(linux || darwin || windows))
+//go:build !(WITHOUT_DOCKER || !(linux || darwin || windows || netbsd))
 
 package container
 

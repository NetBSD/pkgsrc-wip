$NetBSD$

Add support for NetBSD.

--- pkg/container/docker_cli.go.orig	2023-09-23 11:36:33.000000000 +0000
+++ pkg/container/docker_cli.go
@@ -1,4 +1,4 @@
-//go:build !(WITHOUT_DOCKER || !(linux || darwin || windows))
+//go:build !(WITHOUT_DOCKER || !(linux || darwin || windows || netbsd))
 
 // This file is exact copy of https://github.com/docker/cli/blob/9ac8584acfd501c3f4da0e845e3a40ed15c85041/cli/command/container/opts.go
 // appended with license information.

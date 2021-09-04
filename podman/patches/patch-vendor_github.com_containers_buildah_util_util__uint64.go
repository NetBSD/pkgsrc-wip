$NetBSD$

--- vendor/github.com/containers/buildah/util/util_uint64.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ vendor/github.com/containers/buildah/util/util_uint64.go
@@ -1,4 +1,4 @@
-// +build linux,!mips,!mipsle,!mips64,!mips64le
+// +build linux,!mips,!mipsle,!mips64,!mips64le netbsd
 
 package util
 

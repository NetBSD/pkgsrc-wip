$NetBSD$

NetBSD support
https://github.com/containers/buildah/pull/5559

--- vendor/github.com/containers/buildah/copier/hardlink_uint64.go.orig	2024-05-28 23:57:05.911122335 +0000
+++ vendor/github.com/containers/buildah/copier/hardlink_uint64.go
@@ -1,5 +1,5 @@
-//go:build (linux && !mips && !mipsle && !mips64 && !mips64le) || freebsd
-// +build linux,!mips,!mipsle,!mips64,!mips64le freebsd
+//go:build (linux && !mips && !mipsle && !mips64 && !mips64le) || freebsd || netbsd
+// +build linux,!mips,!mipsle,!mips64,!mips64le freebsd netbsd
 
 package copier
 

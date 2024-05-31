$NetBSD$

--- pkg/machine/vmconfigs/config_common.go.orig	2024-05-29 00:05:33.264766331 +0000
+++ pkg/machine/vmconfigs/config_common.go
@@ -1,4 +1,4 @@
-//go:build linux || freebsd
+//go:build linux || freebsd || netbsd
 
 package vmconfigs
 

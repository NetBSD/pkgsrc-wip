$NetBSD$

--- pkg/machine/qemu/machine.go.orig	2024-05-29 00:08:32.713658134 +0000
+++ pkg/machine/qemu/machine.go
@@ -1,4 +1,4 @@
-//go:build linux || freebsd
+//go:build linux || freebsd || netbsd
 
 package qemu
 

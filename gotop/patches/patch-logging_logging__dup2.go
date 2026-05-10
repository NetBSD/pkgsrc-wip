$NetBSD$

Add support for NetBSD.

--- logging/logging_dup2.go.orig	2026-05-06 15:39:51.000000000 +0000
+++ logging/logging_dup2.go
@@ -1,4 +1,4 @@
-// +build linux,!arm64,!riscv64 openbsd,!arm64 freebsd darwin
+// +build linux,!arm64,!riscv64 openbsd,!arm64 freebsd darwin netbsd
 
 package logging
 

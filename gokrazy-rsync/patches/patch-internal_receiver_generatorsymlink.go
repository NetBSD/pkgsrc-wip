$NetBSD$

Allow building for other unixes, not just linux and darwin.

--- internal/receiver/generatorsymlink.go.orig	2026-10-01 05:54:39.671760930 +0000
+++ internal/receiver/generatorsymlink.go
@@ -1,4 +1,4 @@
-//go:build linux || darwin
+//go:build !windows
 
 package receiver
 

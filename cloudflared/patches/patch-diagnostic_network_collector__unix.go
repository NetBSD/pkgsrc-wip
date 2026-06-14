$NetBSD$

Build on NetBSD.

--- diagnostic/network/collector_unix.go.orig	2026-06-14 01:47:32.431444055 +0000
+++ diagnostic/network/collector_unix.go
@@ -1,4 +1,4 @@
-//go:build darwin || linux
+//go:build darwin || linux || netbsd
 
 package diagnostic
 

$NetBSD$

Build on NetBSD.

--- diagnostic/network/collector_unix_test.go.orig	2026-05-27 10:15:36.000000000 +0000
+++ diagnostic/network/collector_unix_test.go
@@ -1,4 +1,4 @@
-//go:build darwin || linux
+//go:build darwin || linux || netbsd
 
 package diagnostic_test
 

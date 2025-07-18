$NetBSD$

Add support for NetBSD.

--- vendor/github.com/VictoriaMetrics/VictoriaMetrics/lib/fs/fadvise_unix.go.orig	2025-07-18 18:21:04.140260699 +0000
+++ vendor/github.com/VictoriaMetrics/VictoriaMetrics/lib/fs/fadvise_unix.go
@@ -1,4 +1,4 @@
-//go:build linux || freebsd
+//go:build linux || freebsd || netbsd
 
 package fs
 

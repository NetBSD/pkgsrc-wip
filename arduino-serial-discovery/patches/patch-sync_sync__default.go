$NetBSD$

--- sync/sync_default.go.orig	2024-02-18 02:17:41.780191456 +0000
+++ sync/sync_default.go
@@ -15,7 +15,7 @@
 // a commercial license, send an email to license@arduino.cc.
 //
 
-//go:build !linux && !windows && !darwin
+//go:build !linux && !windows && !darwin && !netbsd
 
 package sync
 

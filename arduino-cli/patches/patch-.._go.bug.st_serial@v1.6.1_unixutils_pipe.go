$NetBSD$

--- ../go.bug.st/serial@v1.6.1/unixutils/pipe.go.orig	2024-01-28 00:52:11.742808166 +0000
+++ ../go.bug.st/serial@v1.6.1/unixutils/pipe.go
@@ -4,7 +4,7 @@
 // license that can be found in the LICENSE file.
 //
 
-//go:build linux || darwin || freebsd || openbsd
+//go:build linux || darwin || freebsd || netbsd || openbsd
 
 package unixutils
 

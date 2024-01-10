$NetBSD$

add NetBSD support

--- ../go.bug.st/serial@v1.6.0/unixutils/select.go.orig	2024-01-09 09:32:28.935903189 +0000
+++ ../go.bug.st/serial@v1.6.0/unixutils/select.go
@@ -4,7 +4,7 @@
 // license that can be found in the LICENSE file.
 //
 
-//go:build linux || darwin || freebsd || openbsd
+//go:build linux || darwin || freebsd || openbsd || netbsd
 
 package unixutils
 

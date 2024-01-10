$NetBSD$

add NetBSD support

--- ../go.bug.st/serial@v1.6.0/unixutils/pipe.go.orig	2024-01-09 09:32:21.813292581 +0000
+++ ../go.bug.st/serial@v1.6.0/unixutils/pipe.go
@@ -4,7 +4,7 @@
 // license that can be found in the LICENSE file.
 //
 
-//go:build linux || darwin || freebsd || openbsd
+//go:build linux || darwin || freebsd || openbsd || netbsd
 
 package unixutils
 

$NetBSD$

add NetBSD support

--- ../go.bug.st/serial@v1.6.0/serial_unix.go.orig	2024-01-09 09:59:18.713747734 +0000
+++ ../go.bug.st/serial@v1.6.0/serial_unix.go
@@ -4,7 +4,7 @@
 // license that can be found in the LICENSE file.
 //
 
-//go:build linux || darwin || freebsd || openbsd
+//go:build linux || darwin || freebsd || openbsd || netbsd
 
 package serial
 

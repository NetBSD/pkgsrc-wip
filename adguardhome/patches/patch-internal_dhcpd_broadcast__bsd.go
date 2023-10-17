$NetBSD$

--- internal/dhcpd/broadcast_bsd.go.orig	2023-04-12 13:18:02.000000000 +0000
+++ internal/dhcpd/broadcast_bsd.go
@@ -1,4 +1,4 @@
-//go:build freebsd || openbsd
+//go:build freebsd || openbsd || netbsd
 
 package dhcpd
 

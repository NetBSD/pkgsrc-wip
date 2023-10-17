$NetBSD$

--- internal/aghnet/arpdb_bsd.go.orig	2023-04-12 13:18:02.000000000 +0000
+++ internal/aghnet/arpdb_bsd.go
@@ -1,4 +1,4 @@
-//go:build darwin || freebsd
+//go:build darwin || freebsd || netbsd
 
 package aghnet
 

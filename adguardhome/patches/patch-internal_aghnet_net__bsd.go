$NetBSD$

--- internal/aghnet/net_bsd.go.orig	2023-04-12 13:18:02.000000000 +0000
+++ internal/aghnet/net_bsd.go
@@ -1,4 +1,4 @@
-//go:build darwin || freebsd || openbsd
+//go:build darwin || freebsd || openbsd || netbsd
 
 package aghnet
 

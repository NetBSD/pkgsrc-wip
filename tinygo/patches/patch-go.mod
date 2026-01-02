$NetBSD$

--- go.mod.orig	2026-01-02 15:38:34.718034968 +0000
+++ go.mod
@@ -24,6 +24,7 @@ require (
 require (
 	github.com/creack/goselect v0.1.2 // indirect
 	github.com/mattn/go-isatty v0.0.20 // indirect
-	github.com/stretchr/testify v1.8.4 // indirect
 	golang.org/x/text v0.22.0 // indirect
 )
+
+replace go.bug.st/serial => github.com/tnn2/go-serial v0.0.0-20240808132751-d345e1ef8d6d

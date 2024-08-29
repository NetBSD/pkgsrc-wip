$NetBSD$

--- go.mod.orig	2024-08-20 07:21:48.000000000 +0000
+++ go.mod
@@ -31,6 +31,7 @@ require (
 	github.com/josharian/intern v1.0.0 // indirect
 	github.com/mailru/easyjson v0.7.7 // indirect
 	github.com/mattn/go-isatty v0.0.20 // indirect
-	github.com/stretchr/testify v1.8.4 // indirect
 	golang.org/x/text v0.16.0 // indirect
 )
+
+replace go.bug.st/serial => github.com/tnn2/go-serial v0.0.0-20240808132751-d345e1ef8d6d

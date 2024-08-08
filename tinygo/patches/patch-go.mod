$NetBSD$

--- go.mod.orig	2024-08-08 14:51:00.043056325 +0000
+++ go.mod
@@ -47,3 +47,5 @@ require (
 )
 
 replace golang.org/x/tools => github.com/tinygo-org/tools v0.0.0-20240612102102-36af80766fc9
+
+replace go.bug.st/serial => github.com/tnn2/go-serial v0.0.0-20240808132751-d345e1ef8d6d

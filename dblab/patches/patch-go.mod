$NetBSD$

Use ktnb's fork of sqlite-go

--- go.mod.orig	2025-10-23 22:13:16.716927559 +0000
+++ go.mod
@@ -79,3 +79,5 @@ require (
 	modernc.org/mathutil v1.7.1 // indirect
 	modernc.org/memory v1.10.0 // indirect
 )
+
+replace modernc.org/sqlite => gitlab.com/ktnb/sqlite v1.37.0-kev

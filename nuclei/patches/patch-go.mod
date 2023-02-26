$NetBSD$

Use latest pebble version that supports NetBSD.

--- go.mod.orig	2023-02-24 21:13:47.050748523 +0000
+++ go.mod
@@ -299,3 +299,5 @@ require (
 	github.com/xi2/xz v0.0.0-20171230120015-48954b6210f8 // indirect
 	gopkg.in/warnings.v0 v0.1.2 // indirect
 )
+
+replace github.com/cockroachdb/pebble => github.com/cockroachdb/pebble v0.0.0-20230223225144-bc4c9afe47a5

$NetBSD$

Get rid of patch version number to avoid parsing errors of go.mod, i.e.:

 go: errors parsing go.mod:
 .../go.mod:3: invalid go version '1.21.1': must match format 1.23

--- go.mod.orig	2023-09-11 12:40:15.000000000 +0000
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/cloudflare/pint
 
-go 1.21.1
+go 1.21
 
 require (
 	github.com/cespare/xxhash/v2 v2.2.0

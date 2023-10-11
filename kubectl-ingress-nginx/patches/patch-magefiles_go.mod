$NetBSD$

Adjust go version in order to match expected format with only major and
minor per Go 1.20.

--- magefiles/go.mod.orig	2023-10-03 20:22:19.000000000 +0000
+++ magefiles/go.mod
@@ -1,6 +1,6 @@
 module k8s.io/ingress-nginx/magefiles
 
-go 1.21.1
+go 1.21
 
 require (
 	github.com/blang/semver/v4 v4.0.0

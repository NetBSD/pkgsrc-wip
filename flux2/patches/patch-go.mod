$NetBSD$

Use go-ps to support NetBSD.

Shared upstream via:

 <https://github.com/mitchellh/go-ps/pull/59>

--- go.mod.orig	2025-11-27 10:18:48.000000000 +0000
+++ go.mod
@@ -274,3 +274,5 @@ require (
 	sigs.k8s.io/randfill v1.0.0 // indirect
 	sigs.k8s.io/structured-merge-diff/v6 v6.3.0 // indirect
 )
+
+replace github.com/mitchellh/go-ps => github.com/iamleot/go-ps v1.0.1-0.20230107215528-c3e6d0630c23

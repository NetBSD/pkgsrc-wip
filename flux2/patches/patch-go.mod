$NetBSD$

Use go-ps to support NetBSD.

Shared upstream via:

 <https://github.com/mitchellh/go-ps/pull/59>

--- go.mod.orig	2024-09-30 09:29:31.000000000 +0000
+++ go.mod
@@ -256,3 +256,5 @@ require (
 	sigs.k8s.io/json v0.0.0-20221116044647-bc3834ca7abd // indirect
 	sigs.k8s.io/structured-merge-diff/v4 v4.4.1 // indirect
 )
+
+replace github.com/mitchellh/go-ps => github.com/iamleot/go-ps v1.0.1-0.20230107215528-c3e6d0630c23

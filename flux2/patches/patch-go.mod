$NetBSD$

Use go-ps to support NetBSD.

Shared upstream via:

 <https://github.com/mitchellh/go-ps/pull/59>

--- go.mod.orig	2026-04-07 17:29:07.000000000 +0000
+++ go.mod
@@ -267,3 +267,5 @@ require (
 	sigs.k8s.io/randfill v1.0.0 // indirect
 	sigs.k8s.io/structured-merge-diff/v6 v6.3.2-0.20260122202528-d9cc6641c482 // indirect
 )
+
+replace github.com/mitchellh/go-ps => github.com/iamleot/go-ps v1.0.1-0.20230107215528-c3e6d0630c23

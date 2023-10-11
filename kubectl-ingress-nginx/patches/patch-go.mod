$NetBSD$

- Adjust go version in order to match expected format with only major and
  minor per Go 1.20.
- Use go-ps to support NetBSD.
  Shared upstream via: <https://github.com/mitchellh/go-ps/pull/59>

--- go.mod.orig	2023-10-03 20:22:19.000000000 +0000
+++ go.mod
@@ -1,6 +1,6 @@
 module k8s.io/ingress-nginx
 
-go 1.21.1
+go 1.21
 
 require (
 	github.com/armon/go-proxyproto v0.0.0-20210323213023-7e956b284f0a
@@ -124,3 +124,5 @@ require (
 	sigs.k8s.io/structured-merge-diff/v4 v4.2.3 // indirect
 	sigs.k8s.io/yaml v1.3.0 // indirect
 )
+
+replace github.com/mitchellh/go-ps => github.com/iamleot/go-ps v1.0.1-0.20230107215528-c3e6d0630c23

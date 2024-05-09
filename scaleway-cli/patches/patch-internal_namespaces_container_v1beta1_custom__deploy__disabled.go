$NetBSD$

Needs github.com/buildpacks/lifecycle/internal/path that is only for
darwin, linux and windows.

--- internal/namespaces/container/v1beta1/custom_deploy_disabled.go.orig	2024-05-09 20:01:32.287395065 +0000
+++ internal/namespaces/container/v1beta1/custom_deploy_disabled.go
@@ -1,4 +1,4 @@
-//go:build wasm || freebsd
+//go:build !(darwin || linux || windows)
 
 package container
 

$NetBSD$

--- cmd/podman/registry/config.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ cmd/podman/registry/config.go
@@ -54,7 +54,7 @@ func newPodmanConfig() {
 
 	var mode entities.EngineMode
 	switch runtime.GOOS {
-	case "darwin", "windows":
+	case "darwin", "netbsd", "windows":
 		mode = entities.TunnelMode
 	case "linux":
 		// Some linux clients might only be compiled without ABI

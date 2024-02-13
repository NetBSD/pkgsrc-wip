$NetBSD$

--- configuration/configuration.go.orig	2024-02-13 11:38:49.633275198 +0000
+++ configuration/configuration.go
@@ -87,7 +87,7 @@ func getDefaultArduinoDataDir() string {
 	}
 
 	switch runtime.GOOS {
-	case "linux":
+	case "linux", "netbsd":
 		return filepath.Join(userHomeDir, ".arduino15")
 	case "darwin":
 		return filepath.Join(userHomeDir, "Library", "Arduino15")
@@ -112,7 +112,7 @@ func getDefaultUserDir() string {
 	}
 
 	switch runtime.GOOS {
-	case "linux":
+	case "linux", "netbsd":
 		return filepath.Join(userHomeDir, "Arduino")
 	case "darwin":
 		return filepath.Join(userHomeDir, "Documents", "Arduino")

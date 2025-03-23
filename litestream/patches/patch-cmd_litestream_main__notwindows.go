$NetBSD$

Use PKG_SYSCONFDIR instead of hardcoding /etc.

--- cmd/litestream/main_notwindows.go.orig	2025-03-23 19:27:04.461508413 +0000
+++ cmd/litestream/main_notwindows.go
@@ -9,7 +9,7 @@ import (
 	"syscall"
 )
 
-const defaultConfigPath = "/etc/litestream.yml"
+const defaultConfigPath = "@PKG_SYSCONFDIR@/litestream.yml"
 
 func isWindowsService() (bool, error) {
 	return false, nil

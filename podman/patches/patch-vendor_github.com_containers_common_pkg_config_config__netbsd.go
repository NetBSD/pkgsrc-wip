$NetBSD$

--- vendor/github.com/containers/common/pkg/config/config_netbsd.go.orig	2021-09-04 12:43:05.851513218 +0000
+++ vendor/github.com/containers/common/pkg/config/config_netbsd.go
@@ -0,0 +1,17 @@
+package config
+
+import (
+	"os"
+)
+
+// podman remote clients on darwin cannot use unshare.isRootless() to determine the configuration file locations.
+func customConfigFile() (string, error) {
+	if path, found := os.LookupEnv("CONTAINERS_CONF"); found {
+		return path, nil
+	}
+	return rootlessConfigPath()
+}
+
+func ifRootlessConfigPath() (string, error) {
+	return rootlessConfigPath()
+}

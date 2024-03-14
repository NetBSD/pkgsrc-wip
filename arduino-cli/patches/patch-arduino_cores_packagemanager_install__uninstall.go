$NetBSD$

--- arduino/cores/packagemanager/install_uninstall.go.orig	2024-03-09 06:51:20.561238937 +0000
+++ arduino/cores/packagemanager/install_uninstall.go
@@ -19,11 +19,13 @@ import (
 	"bytes"
 	"encoding/json"
 	"fmt"
+	"path/filepath"
 	"runtime"
 
 	"github.com/arduino/arduino-cli/arduino"
 	"github.com/arduino/arduino-cli/arduino/cores"
 	"github.com/arduino/arduino-cli/arduino/cores/packageindex"
+	"github.com/arduino/arduino-cli/configuration"
 	"github.com/arduino/arduino-cli/executils"
 	rpc "github.com/arduino/arduino-cli/rpc/cc/arduino/cli/commands/v1"
 	"github.com/arduino/go-paths-helper"
@@ -79,6 +81,24 @@ func (pme *Explorer) DownloadAndInstallP
 	skipPostInstall bool, skipPreUninstall bool) error {
 	log := pme.log.WithField("platform", platformRelease)
 
+	// Search for third-party packages
+	if runtime.GOOS == "netbsd" {
+		prefixDir := paths.New("/usr/pkg")
+		platformDir := filepath.Join("packages", platformRelease.Platform.Package.Name, "hardware", platformRelease.Platform.Name, platformRelease.Version.String())
+		packageDir := prefixDir.Join("arduino15", platformDir)
+		_, err := packageDir.IsDirCheck()
+		if err != nil {
+			return fmt.Errorf("%w", err)
+		}
+
+		dataDir := configuration.Settings.GetString("directories.Data")
+		destDir := paths.New(filepath.Join(dataDir, platformDir))
+		if err := packageDir.CopyDirTo(destDir); err != nil {
+			return fmt.Errorf("%w", err)
+		}
+		return nil
+	}
+
 	// Prerequisite checks before install
 	toolsToInstall := []*cores.ToolRelease{}
 	for _, tool := range requiredTools {

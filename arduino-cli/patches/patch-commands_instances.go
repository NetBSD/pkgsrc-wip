$NetBSD$

--- commands/instances.go.orig	2024-02-13 11:40:35.243625117 +0000
+++ commands/instances.go
@@ -19,7 +19,9 @@ import (
 	"context"
 	"fmt"
 	"net/url"
+	"os"
 	"path/filepath"
+	"runtime"
 	"strings"
 
 	"github.com/arduino/arduino-cli/arduino"
@@ -48,6 +50,28 @@ var tr = i18n.Tr
 func installTool(pm *packagemanager.PackageManager, tool *cores.ToolRelease, downloadCB rpc.DownloadProgressCB, taskCB rpc.TaskProgressCB) error {
 	pme, release := pm.NewExplorer()
 	defer release()
+	// Search for third-party packages
+	if runtime.GOOS == "netbsd" {
+		prefixDir := paths.New("/usr/pkg")
+		subDir := filepath.Join("packages", tool.Tool.Package.Name, "tools", tool.Tool.Name)
+		packageDir := prefixDir.Join("arduino15", subDir)
+		_, err := packageDir.IsDirCheck()
+		if err != nil {
+			return fmt.Errorf("%w", err)
+		}
+
+		userHomeDir, err := os.UserHomeDir()
+		if err != nil {
+			return fmt.Errorf("%w", err)
+		}
+
+		userDataDir := paths.New(filepath.Join(userHomeDir, ".arduino15", subDir))
+		if err := packageDir.CopyDirTo(userDataDir); err != nil {
+			return fmt.Errorf("%w", err)
+		}
+		return nil
+	}
+
 	taskCB(&rpc.TaskProgress{Name: tr("Downloading missing tool %s", tool)})
 	if err := pme.DownloadToolRelease(tool, nil, downloadCB); err != nil {
 		return fmt.Errorf(tr("downloading %[1]s tool: %[2]s"), tool, err)

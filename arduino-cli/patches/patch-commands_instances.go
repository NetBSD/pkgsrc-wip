$NetBSD$

--- commands/instances.go.orig	2024-02-19 13:15:51.000000000 +0000
+++ commands/instances.go
@@ -20,6 +20,7 @@ import (
 	"fmt"
 	"net/url"
 	"path/filepath"
+	"runtime"
 	"strings"
 
 	"github.com/arduino/arduino-cli/arduino"
@@ -48,6 +49,24 @@ var tr = i18n.Tr
 func installTool(pm *packagemanager.PackageManager, tool *cores.ToolRelease, downloadCB rpc.DownloadProgressCB, taskCB rpc.TaskProgressCB) error {
 	pme, release := pm.NewExplorer()
 	defer release()
+	// Search for third-party packages
+	if runtime.GOOS == "netbsd" {
+		prefixDir := paths.New("/usr/pkg")
+		toolDir := filepath.Join("packages", tool.Tool.Package.Name, "tools", tool.Tool.Name, tool.Version.String())
+		packageDir := prefixDir.Join("arduino15", toolDir)
+		_, err := packageDir.IsDirCheck()
+		if err != nil {
+			return fmt.Errorf("%w", err)
+		}
+
+		dataDir := configuration.Settings.GetString("directories.Data")
+		destDir := paths.New(filepath.Join(dataDir, toolDir))
+		if err := packageDir.CopyDirTo(destDir); err != nil {
+			return fmt.Errorf("%w", err)
+		}
+		return nil
+	}
+
 	taskCB(&rpc.TaskProgress{Name: tr("Downloading missing tool %s", tool)})
 	if err := pme.DownloadToolRelease(tool, nil, downloadCB); err != nil {
 		return fmt.Errorf(tr("downloading %[1]s tool: %[2]s"), tool, err)

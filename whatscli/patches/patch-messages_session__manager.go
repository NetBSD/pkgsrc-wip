$NetBSD$

Disable notifications.

godbus/dbus needs to be ported on NetBSD.

This is probably just a copypaste of `transport_unixcred_openbsd.go' to
`transport_unixcred_netbsd.go' but this should be also properly tested,
submitted upstream and once a release lands upstream we can get rid of this
workaround.

For the moment just disable them for laziness.

--- messages/session_manager.go.orig	2021-04-10 10:31:00.000000000 +0000
+++ messages/session_manager.go
@@ -16,7 +16,7 @@ import (
 	"github.com/Rhymen/go-whatsapp"
 	"github.com/gabriel-vasile/mimetype"
 	"github.com/gdamore/tcell/v2"
-	"github.com/gen2brain/beeep"
+	// "github.com/gen2brain/beeep"
 	"github.com/normen/whatscli/config"
 	"github.com/normen/whatscli/qrcode"
 	"github.com/rivo/tview"
@@ -995,5 +995,6 @@ func notify(title, message string) error
 		_, err := fmt.Printf("\a")
 		return err
 	}
-	return beeep.Notify(title, message, "")
+	// return beeep.Notify(title, message, "")
+	return nil
 }

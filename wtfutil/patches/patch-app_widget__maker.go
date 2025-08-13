$NetBSD$

Avoid godbus/dbus dependency that is not supported by NetBSD.

--- app/widget_maker.go.orig	2025-08-13 08:53:44.143343848 +0000
+++ app/widget_maker.go
@@ -63,7 +63,6 @@ import (
 	"github.com/wtfutil/wtf/modules/rollbar"
 	"github.com/wtfutil/wtf/modules/security"
 	"github.com/wtfutil/wtf/modules/spacex"
-	"github.com/wtfutil/wtf/modules/spotify"
 	"github.com/wtfutil/wtf/modules/spotifyweb"
 	"github.com/wtfutil/wtf/modules/status"
 	"github.com/wtfutil/wtf/modules/steam"
@@ -298,9 +297,6 @@ func MakeWidget(
 	case "spacex":
 		settings := spacex.NewSettingsFromYAML(moduleName, moduleConfig, config)
 		widget = spacex.NewWidget(tviewApp, redrawChan, settings)
-	case "spotify":
-		settings := spotify.NewSettingsFromYAML(moduleName, moduleConfig, config)
-		widget = spotify.NewWidget(tviewApp, redrawChan, pages, settings)
 	case "spotifyweb":
 		settings := spotifyweb.NewSettingsFromYAML(moduleName, moduleConfig, config)
 		widget = spotifyweb.NewWidget(tviewApp, redrawChan, pages, settings)

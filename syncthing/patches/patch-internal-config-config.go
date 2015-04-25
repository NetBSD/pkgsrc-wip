$NetBSD: patch-internal-config-config.go,v 1.2 2015/04/25 16:59:22 tnn2 Exp $

--- internal/config/config.go.orig	2015-04-22 00:37:18.000000000 +0000
+++ internal/config/config.go
@@ -233,7 +233,7 @@ type OptionsConfiguration struct {
 	URAccepted              int      `xml:"urAccepted" json:"urAccepted"` // Accepted usage reporting version; 0 for off (undecided), -1 for off (permanently)
 	URUniqueID              string   `xml:"urUniqueID" json:"urUniqueId"` // Unique ID for reporting purposes, regenerated when UR is turned on.
 	RestartOnWakeup         bool     `xml:"restartOnWakeup" json:"restartOnWakeup" default:"true"`
-	AutoUpgradeIntervalH    int      `xml:"autoUpgradeIntervalH" json:"autoUpgradeIntervalH" default:"12"` // 0 for off
+	AutoUpgradeIntervalH    int      `xml:"autoUpgradeIntervalH" json:"autoUpgradeIntervalH" default:"0"` // 0 for off
 	KeepTemporariesH        int      `xml:"keepTemporariesH" json:"keepTemporariesH" default:"24"`         // 0 for off
 	CacheIgnoredFiles       bool     `xml:"cacheIgnoredFiles" json:"cacheIgnoredFiles" default:"true"`
 	ProgressUpdateIntervalS int      `xml:"progressUpdateIntervalS" json:"progressUpdateIntervalS" default:"5"`

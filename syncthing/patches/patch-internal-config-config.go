$NetBSD: patch-internal-config-config.go,v 1.1 2015/03/24 09:36:40 tnn2 Exp $

--- internal/config/config.go.orig	2015-03-15 15:42:52.000000000 +0000
+++ internal/config/config.go
@@ -178,7 +178,7 @@ type OptionsConfiguration struct {
 	URAccepted              int      `xml:"urAccepted"` // Accepted usage reporting version; 0 for off (undecided), -1 for off (permanently)
 	URUniqueID              string   `xml:"urUniqueID"` // Unique ID for reporting purposes, regenerated when UR is turned on.
 	RestartOnWakeup         bool     `xml:"restartOnWakeup" default:"true"`
-	AutoUpgradeIntervalH    int      `xml:"autoUpgradeIntervalH" default:"12"` // 0 for off
+	AutoUpgradeIntervalH    int      `xml:"autoUpgradeIntervalH" default:"0"` // 0 for off
 	KeepTemporariesH        int      `xml:"keepTemporariesH" default:"24"`     // 0 for off
 	CacheIgnoredFiles       bool     `xml:"cacheIgnoredFiles" default:"true"`
 	ProgressUpdateIntervalS int      `xml:"progressUpdateIntervalS" default:"5"`

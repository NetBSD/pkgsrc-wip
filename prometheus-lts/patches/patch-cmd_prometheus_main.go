$NetBSD: patch-cmd_prometheus_main.go,v 1.3 2022/03/11 19:56:00 tnn Exp $

Add prefix for SYSCONFDIR and VARBASE to store configuration file and metrics data at the correct location.

--- cmd/prometheus/main.go.orig	2026-01-21 13:27:59.000000000 +0000
+++ cmd/prometheus/main.go
@@ -354,7 +354,7 @@ func main() {
 	a.HelpFlag.Short('h')
 
 	a.Flag("config.file", "Prometheus configuration file path.").
-		Default("prometheus.yml").StringVar(&cfg.configFile)
+		Default("@PKG_SYSCONFDIR@/prometheus.yml").StringVar(&cfg.configFile)
 
 	a.Flag("config.auto-reload-interval", "Specifies the interval for checking and automatically reloading the Prometheus configuration file upon detecting changes.").
 		Default("30s").SetValue(&cfg.autoReloadInterval)
@@ -414,10 +414,10 @@ func main() {
 		Default("false").BoolVar(&cfg.web.EnableOTLPWriteReceiver)
 
 	a.Flag("web.console.templates", "Path to the console template directory, available at /consoles.").
-		Default("consoles").StringVar(&cfg.web.ConsoleTemplatesPath)
+		Default("@PKG_SYSCONFDIR@/consoles").StringVar(&cfg.web.ConsoleTemplatesPath)
 
 	a.Flag("web.console.libraries", "Path to the console library directory.").
-		Default("console_libraries").StringVar(&cfg.web.ConsoleLibrariesPath)
+		Default("@PKG_SYSCONFDIR@/console_libraries").StringVar(&cfg.web.ConsoleLibrariesPath)
 
 	a.Flag("web.page-title", "Document title of Prometheus instance.").
 		Default("Prometheus Time Series Collection and Processing Server").StringVar(&cfg.web.PageTitle)
@@ -426,7 +426,7 @@ func main() {
 		Default(".*").StringVar(&cfg.corsRegexString)
 
 	serverOnlyFlag(a, "storage.tsdb.path", "Base path for metrics storage.").
-		Default("data/").StringVar(&cfg.serverStoragePath)
+		Default("@VARBASE@/lib/prometheus/data/").StringVar(&cfg.serverStoragePath)
 
 	serverOnlyFlag(a, "storage.tsdb.min-block-duration", "Minimum duration of a data block before being persisted. For use in testing.").
 		Hidden().Default("2h").SetValue(&cfg.tsdb.MinBlockDuration)

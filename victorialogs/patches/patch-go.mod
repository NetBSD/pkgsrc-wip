$NetBSD$

Relax Go version requirement.

At the moment in pkgsrc we have Go 1.24.5.

--- go.mod.orig	2025-08-12 08:26:52.738947623 +0000
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/VictoriaMetrics/VictoriaLogs
 
-go 1.24.6
+go 1.24
 
 require (
 	github.com/VictoriaMetrics/VictoriaMetrics v0.0.0-20250804081214-847398b356ae

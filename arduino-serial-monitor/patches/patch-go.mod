$NetBSD$

--- go.mod.orig	2024-02-21 14:32:13.000000000 +0000
+++ go.mod
@@ -2,6 +2,8 @@ module github.com/arduino/serial-monitor
 
 go 1.18
 
+replace go.bug.st/serial v1.6.2 => github.com/picohive/go-serial v1.6.2
+
 require (
 	github.com/arduino/pluggable-monitor-protocol-handler v0.9.2
 	go.bug.st/serial v1.6.2

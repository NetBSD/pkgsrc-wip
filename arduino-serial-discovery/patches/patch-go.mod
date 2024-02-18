$NetBSD$

--- go.mod.orig	2023-02-09 15:30:05.000000000 +0000
+++ go.mod
@@ -1,6 +1,7 @@
 module github.com/arduino/serial-discovery
 
 go 1.19
+replace go.bug.st/serial v1.5.0 => github.com/picohive/go-serial v1.6.2
 
 require (
 	github.com/arduino/go-properties-orderedmap v1.7.1

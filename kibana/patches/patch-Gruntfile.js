$NetBSD: patch-Gruntfile.js,v 1.2 2015/08/19 21:02:45 wiedi Exp $
Just build a generic target (Without node binaries bundled)

--- Gruntfile.js.orig	2015-06-29 16:45:18.000000000 +0000
+++ Gruntfile.js
@@ -15,7 +15,7 @@ module.exports = function (grunt) {
     configFile: __dirname + '/src/server/config/kibana.yml',
 
     nodeVersion: '0.10.35',
-    platforms: ['darwin-x64', 'linux-x64', 'linux-x86', 'windows'],
+    platforms: [],
     services: [ [ 'launchd', '10.9'], [ 'upstart', '1.5'], [ 'systemd', 'default'], [ 'sysv', 'lsb-3.1' ] ],
 
     unitTestDir: __dirname + '/test/unit',

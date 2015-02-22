$NetBSD: patch-Gruntfile.js,v 1.1 2015/02/22 20:10:34 mbowie Exp $
Just build a generic target (Without node binaries bundled)

--- Gruntfile.js.orig	2015-02-20 13:44:12.000000000 +0000
+++ Gruntfile.js	2015-02-20 13:44:29.000000000 +0000
@@ -15,7 +15,7 @@
     configFile: __dirname + '/src/server/config/kibana.yml',
 
     nodeVersion: '0.10.35',
-    platforms: ['darwin-x64', 'linux-x64', 'linux-x86', 'windows'],
+    platforms: [],
 
     unitTestDir: __dirname + '/test/unit',
     testUtilsDir: __dirname + '/test/utils',

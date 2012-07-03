$NetBSD: patch-tools_installer.js,v 1.1 2012/07/03 08:49:00 fhajny Exp $

Fix man path reference.
--- tools/installer.js.orig	2012-06-29 09:11:19.000000000 +0000
+++ tools/installer.js
@@ -102,7 +102,7 @@ if (cmd === 'install') {
   ], 'include/node/');
 
   // man page
-  copy(['doc/node.1'], 'share/man/man1/');
+  copy(['doc/node.1'], '@PKGMANDIR@/man1/');
 
   // dtrace
   if (!process.platform.match(/^linux/)) {

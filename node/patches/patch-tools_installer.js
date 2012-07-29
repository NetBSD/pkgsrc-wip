$NetBSD: patch-tools_installer.js,v 1.2 2012/07/29 20:12:38 genolopolis Exp $

--- tools/installer.js.orig	2012-07-29 18:47:12.000000000 +0000
+++ tools/installer.js
@@ -93,7 +93,7 @@ if (cmd === 'install') {
   ], 'include/node/');
 
   // man page
-  copy(['doc/node.1'], 'share/man/man1/');
+  copy(['doc/node.1'], 'man/man1/');
 
   // dtrace
   if (!process.platform.match(/^linux/)) {
@@ -130,7 +130,7 @@ if (cmd === 'install') {
     // a bit annoying.  If it's a symlink, skip it.
     var isSymlink = false;
     var exists = true;
-    var npmDir = path.resolve(node_prefix, 'lib/node_modules/npm');
+    var npmDir = path.resolve(dest_dir + "/" + node_prefix, 'lib/node_modules/npm');
     try {
       var st = fs.lstatSync(npmDir);
       isSymlink = st.isSymbolicLink();

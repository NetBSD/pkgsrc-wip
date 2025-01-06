$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/common/assertSnapshot.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/common/assertSnapshot.js
@@ -83,6 +83,7 @@ async function spawnAndAssert(filename, 
     tty ?
       [path.join(__dirname, '../..', 'tools/pseudo-tty.py'), process.execPath, ...flags, filename] :
       [...flags, filename];
+  if (options && options.env) options.env.ELECTRON_RUN_AS_NODE = 1;
   const { stdout, stderr } = await common.spawnPromisified(executable, args, options);
   await assertSnapshot(transform(`${stdout}${stderr}`), filename);
 }

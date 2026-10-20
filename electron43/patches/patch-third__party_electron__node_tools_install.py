$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/tools/install.py.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/tools/install.py
@@ -198,10 +198,7 @@ def files(options, action):
   action(options, [os.path.join(options.v8_dir, 'tools/gdbinit')], 'share/doc/node/')
   action(options, [os.path.join(options.v8_dir, 'tools/lldb_commands.py')], 'share/doc/node/')
 
-  if 'openbsd' in sys.platform:
-    action(options, ['doc/node.1'], 'man/man1/')
-  else:
-    action(options, ['doc/node.1'], 'share/man/man1/')
+  action(options, ['doc/node.1'], os.environ.get('PKGMANDIR') + '/man1/')
 
   if 'true' == options.variables.get('node_install_npm'):
     npm_files(options, action)

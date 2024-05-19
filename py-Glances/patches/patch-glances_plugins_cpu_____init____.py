$NetBSD$

Disable system call counts in BSD.

--- glances/plugins/cpu/__init__.py.orig	2024-05-18 09:31:15.000000000 +0000
+++ glances/plugins/cpu/__init__.py
@@ -11,7 +11,7 @@
 import psutil
 
 from glances.cpu_percent import cpu_percent
-from glances.globals import LINUX, SUNOS, WINDOWS, iterkeys
+from glances.globals import BSD, LINUX, SUNOS, WINDOWS, iterkeys
 from glances.plugins.core import PluginModel as CorePluginModel
 from glances.plugins.plugin.model import GlancesPluginModel
 
@@ -377,8 +377,8 @@ class PluginModel(GlancesPluginModel):
             ret.extend(self.curse_add_stat('dpc', width=15))
         # Steal CPU usage
         ret.extend(self.curse_add_stat('steal', width=14, header='  '))
-        if not LINUX:
-            # syscalls: number of system calls since boot. Always set to 0 on Linux. (do not display)
+        if not LINUX and not BSD:
+            # syscalls: number of system calls since boot. Always set to 0 on Linux and BSD. (do not display)
             ret.extend(self.curse_add_stat('syscalls', width=15, header='  '))
         else:
             # So instead on Linux we display the guest CPU usage (see #2667)

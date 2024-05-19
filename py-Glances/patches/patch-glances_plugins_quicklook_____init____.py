$NetBSD$

It seems cpu_hz_current and cpu_hz is not available in NetBSD, so add additional
check to see if the key exists.

--- glances/plugins/quicklook/__init__.py.orig	2024-05-18 09:31:15.000000000 +0000
+++ glances/plugins/quicklook/__init__.py
@@ -111,10 +111,12 @@ class PluginModel(GlancesPluginModel):
             # Get system information
             cpu_info = cpu_percent.get_info()
             stats['cpu_name'] = cpu_info['cpu_name']
-            stats['cpu_hz_current'] = (
-                self._mhz_to_hz(cpu_info['cpu_hz_current']) if cpu_info['cpu_hz_current'] is not None else None
-            )
-            stats['cpu_hz'] = self._mhz_to_hz(cpu_info['cpu_hz']) if cpu_info['cpu_hz'] is not None else None
+            if 'cpu_hz_current' in cpu_info:
+                stats['cpu_hz_current'] = (
+                    self._mhz_to_hz(cpu_info['cpu_hz_current']) if cpu_info['cpu_hz_current'] is not None else None
+                )
+            if 'cpu_hz' in cpu_info:
+                stats['cpu_hz'] = self._mhz_to_hz(cpu_info['cpu_hz']) if cpu_info['cpu_hz'] is not None else None
 
             # Get the CPU percent value (global and per core)
             # Stats is shared across all plugins

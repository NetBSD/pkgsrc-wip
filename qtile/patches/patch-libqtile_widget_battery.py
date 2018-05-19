$NetBSD$

Don't assume sysfs is present.

--- libqtile/widget/battery.py.orig	2018-03-01 13:31:23.000000000 +0000
+++ libqtile/widget/battery.py
@@ -63,12 +63,11 @@ class _Battery(base._TextBox):
     filenames = {}
 
     def _get_battery_name():
-        bats = [f for f in os.listdir(BAT_DIR) if f.startswith('BAT')]
-
-        if bats:
-            return bats[0]
-        else:
-            return 'BAT0'
+        if os.path.isdir(BAT_DIR):
+            bats = [f for f in os.listdir(BAT_DIR) if f.startswith('BAT')]
+            if bats:
+                return bats[0]
+        return 'BAT0'
 
     defaults = [
         ('battery_name', _get_battery_name(), 'ACPI name of a battery, usually BAT0'),

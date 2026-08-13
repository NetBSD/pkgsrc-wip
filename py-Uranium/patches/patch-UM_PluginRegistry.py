$NetBSD$

Replace deprecated imp module with importlib.

From e86d717035af317dab5d62851181873ec3c38ebe Mon Sep 17 00:00:00 2001

--- UM/PluginRegistry.py.orig	2022-01-10 15:38:09.000000000 +0000
+++ UM/PluginRegistry.py
@@ -1,11 +1,13 @@
-# Copyright (c) 2021 Ultimaker B.V.
+# Copyright (c) 2023 UltiMaker
 # Uranium is released under the terms of the LGPLv3 or higher.
 
-import imp
+import importlib.util
+import importlib.machinery
 import json
 import os
 import shutil  # For deleting plugin directories;
 import stat  # For setting file permissions correctly;
+import sys
 import time
 import types
 import zipfile
@@ -684,7 +686,10 @@ class PluginRegistry(QObject):
             except:
                 pass
         try:
-            file, path, desc = imp.find_module(plugin_id, [final_location])
+            spec = importlib.machinery.PathFinder().find_spec(plugin_id, [final_location])
+            if len(spec.submodule_search_locations) != 1:
+                raise IndexError(f"Attempt to load plugin '{plugin_id}' from {len(spec.submodule_search_locations)} locations.")
+            path = spec.submodule_search_locations[0]
         except Exception:
             Logger.logException("e", "Import error when importing %s", plugin_id)
             return None
@@ -705,13 +710,12 @@ class PluginRegistry(QObject):
                 return None
 
         try:
-            module = imp.load_module(plugin_id, file, path, desc) #type: ignore #MyPy gets the wrong output type from imp.find_module for some reason.
+            module = importlib.util.module_from_spec(spec)
+            sys.modules[plugin_id] = module
+            spec.loader.exec_module(module)
         except Exception:
             Logger.logException("e", "Import error loading module %s", plugin_id)
             return None
-        finally:
-            if file:
-                os.close(file) #type: ignore #MyPy gets the wrong output type from imp.find_module for some reason.
         self._found_plugins[plugin_id] = module
         return module
 

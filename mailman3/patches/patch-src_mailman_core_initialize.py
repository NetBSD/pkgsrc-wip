$NetBSD$

Use PKG_SYSCONFDIR for default config file.

--- src/mailman/core/initialize.py.orig	2017-11-18 01:23:39.000000000 +0000
+++ src/mailman/core/initialize.py
@@ -68,7 +68,7 @@ def search_for_configuration_file():
     if os.path.exists(config_path):
         return os.path.abspath(config_path)
     # /etc/mailman.cfg
-    config_path = '/etc/mailman.cfg'
+    config_path = '@PKG_SYSCONFDIR@/mailman.cfg'
     if os.path.exists(config_path):
         return os.path.abspath(config_path)
     # /etc/mailman3/mailman.cfg

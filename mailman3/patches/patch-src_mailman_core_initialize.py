$NetBSD$

Use PKG_SYSCONFDIR for default config file.

--- src/mailman/core/initialize.py.orig	2017-02-10 16:58:52.000000000 +0000
+++ src/mailman/core/initialize.py
@@ -68,7 +68,7 @@ def search_for_configuration_file():
     if os.path.exists(config_path):
         return os.path.abspath(config_path)
     # /etc/mailman.cfg
-    config_path = '/etc/mailman.cfg'
+    config_path = '@PKG_SYSCONFDIR@/mailman.cfg'
     if os.path.exists(config_path):
         return os.path.abspath(config_path)
     # $argv0/../../etc/mailman.cfg

$NetBSD$

--- cloudinit/settings.py.orig	2026-07-27 14:56:24.000000000 +0000
+++ cloudinit/settings.py
@@ -12,9 +12,9 @@ CFG_ENV_NAME = "CLOUD_CFG"
 CFG_ENV_NAME = "CLOUD_CFG"
 
 # This is expected to be a yaml formatted file
-CLOUD_CONFIG = "/etc/cloud/cloud.cfg"
+CLOUD_CONFIG = "/usr/pkg/etc/cloud/cloud.cfg"
 
-CLEAN_RUNPARTS_DIR = "/etc/cloud/clean.d"
+CLEAN_RUNPARTS_DIR = "/usr/pkg/etc/cloud/clean.d"
 
 DEFAULT_RUN_DIR = "/run/cloud-init"
 

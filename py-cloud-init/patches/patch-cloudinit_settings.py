$NetBSD$

--- cloudinit/settings.py.orig	2026-11-14 20:35:04.420832518 +0000
+++ cloudinit/settings.py
@@ -12,11 +12,11 @@ CFG_ENV_NAME = "CLOUD_CFG"
 CFG_ENV_NAME = "CLOUD_CFG"
 
 # This is expected to be a yaml formatted file
-CLOUD_CONFIG = "/etc/cloud/cloud.cfg"
+CLOUD_CONFIG = "/usr/pkg/etc/cloud/cloud.cfg"
 
-CLEAN_RUNPARTS_DIR = "/etc/cloud/clean.d"
+CLEAN_RUNPARTS_DIR = "/usr/pkg/etc/cloud/clean.d"
 
-DEFAULT_RUN_DIR = "/run/cloud-init"
+DEFAULT_RUN_DIR = "/var/run/cloud-init"
 
 # What u get if no config is provided
 CFG_BUILTIN = {

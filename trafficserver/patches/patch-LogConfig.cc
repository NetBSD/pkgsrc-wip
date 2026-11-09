$NetBSD$

- Incorrect param name used here.  This is an upstream bug.

diff --git src/proxy/logging/LogConfig.cc src/proxy/logging/LogConfig.cc
index f2c07d8a23..287977d04e 100644
--- src/proxy/logging/LogConfig.cc
+++ src/proxy/logging/LogConfig.cc
@@ -444,7 +444,7 @@ LogConfig::register_config_callbacks()
     "proxy.config.log.max_secs_per_buffer",
     "proxy.config.log.max_space_mb_for_logs",
     "proxy.config.log.max_space_mb_headroom",
-    "proxy.config.log.error_log_filename",
+    "proxy.config.error.logfile.filename",
     "proxy.config.log.logfile_perm",
     "proxy.config.log.hostname",
     "proxy.config.log.logfile_dir",

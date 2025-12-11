$NetBSD$

--- src/libsystemd/sd-bus/test-bus-creds.c.orig	2025-12-11 12:18:32.959056564 +0000
+++ src/libsystemd/sd-bus/test-bus-creds.c
@@ -14,7 +14,7 @@ int main(int argc, char *argv[]) {
         test_setup_logging(LOG_DEBUG);
 
         r = sd_bus_creds_new_from_pid(&creds, 0, _SD_BUS_CREDS_ALL);
-        log_full_errno(r < 0 ? LOG_ERR : LOG_DEBUG, r, "sd_bus_creds_new_from_pid: %m");
+        log_full_errno(r < 0 ? LOG_ERR : LOG_DEBUG, r, LOG_ERR_FMT("sd_bus_creds_new_from_pid", r));
         assert_se(r >= 0);
 
         bus_creds_dump(creds, NULL, true);

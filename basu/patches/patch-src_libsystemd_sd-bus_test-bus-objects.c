$NetBSD$

--- src/libsystemd/sd-bus/test-bus-objects.c.orig	2025-12-11 12:20:54.789852232 +0000
+++ src/libsystemd/sd-bus/test-bus-objects.c
@@ -247,14 +247,14 @@ static void *server(void *p) {
 
                 r = sd_bus_process(bus, NULL);
                 if (r < 0) {
-                        log_error_errno(r, "Failed to process requests: %m");
+                        log_error_errno(r, LOG_ERR_FMT("Failed to process requests", r));
                         goto fail;
                 }
 
                 if (r == 0) {
                         r = sd_bus_wait(bus, (uint64_t) -1);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to wait: %m");
+                                log_error_errno(r, LOG_ERR_FMT("Failed to wait", r));
                                 goto fail;
                         }
 

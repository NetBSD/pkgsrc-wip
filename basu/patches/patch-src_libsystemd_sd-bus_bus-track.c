$NetBSD$

* Fix logging, on NetBSD %m is only allowed in syslog(3) like function

--- src/libsystemd/sd-bus/bus-track.c.orig	2025-12-11 10:48:49.464837646 +0000
+++ src/libsystemd/sd-bus/bus-track.c
@@ -373,7 +373,7 @@ void bus_track_dispatch(sd_bus_track *tr
 
         r = track->handler(track, track->userdata);
         if (r < 0)
-                log_debug_errno(r, "Failed to process track handler: %m");
+                log_debug_errno(r, LOG_ERR_FMT("Failed to process track handler", r));
         else if (r == 0)
                 bus_track_add_to_queue(track);
 

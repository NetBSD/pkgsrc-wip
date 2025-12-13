$NetBSD$

* On NetBSD ucred is unpcbid

--- src/libsystemd/sd-bus/bus-control.c.orig	2025-12-11 10:18:56.189627357 +0000
+++ src/libsystemd/sd-bus/bus-control.c
@@ -743,6 +743,22 @@ _public_ int sd_bus_get_owner_creds(sd_b
                 return -ENOMEM;
 
         if (bus->ucred_valid) {
+#if defined(__NetBSD__)
+                if (pid_is_valid(bus->ucred.unp_pid)) {
+                        pid = c->pid = bus->ucred.unp_pid;
+                        c->mask |= SD_BUS_CREDS_PID & mask;
+                }
+
+                if (uid_is_valid(bus->ucred.unp_euid)) {
+                        c->euid = bus->ucred.unp_euid;
+                        c->mask |= SD_BUS_CREDS_EUID & mask;
+                }
+
+                if (gid_is_valid(bus->ucred.unp_egid)) {
+                        c->egid = bus->ucred.unp_egid;
+                        c->mask |= SD_BUS_CREDS_EGID & mask;
+                }
+#else
                 if (pid_is_valid(bus->ucred.pid)) {
                         pid = c->pid = bus->ucred.pid;
                         c->mask |= SD_BUS_CREDS_PID & mask;
@@ -757,6 +773,7 @@ _public_ int sd_bus_get_owner_creds(sd_b
                         c->egid = bus->ucred.gid;
                         c->mask |= SD_BUS_CREDS_EGID & mask;
                 }
+#endif
         }
 
         if (do_label) {

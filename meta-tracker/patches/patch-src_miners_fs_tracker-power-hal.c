$NetBSD: patch-src_miners_fs_tracker-power-hal.c,v 1.1 2013/10/18 10:53:41 makoto Exp $

# tracker_miner_fs-tracker-power-hal.o: In function `tracker_power_init':
# tracker-power-hal.c:(.text+0x447): undefined reference to `dbus_connection_setup_with_g_main'

--- meta-tracker/work/tracker-0.16.2/src/miners/fs/tracker-power-hal.c.orig	2013-10-16 20:44:40.000000000 +0900
+++ src/miners/fs/tracker-power-hal.c	2013-10-16 20:46:45.000000000 +0900
@@ -25,6 +25,7 @@
 #include <string.h>
 
 #include <libhal.h>
+#include "dbus/dbus-glib-lowlevel.h"
 
 #include <libtracker-common/tracker-log.h>
 #include <libtracker-common/tracker-utils.h>

$NetBSD$

* NetBSD's sysctl is different than in other BSD's,
* use upower backend

--- src/modules/battery/e_mod_sysctl.c.orig	2020-07-26 16:39:12.087314600 +0000
+++ src/modules/battery/e_mod_sysctl.c
@@ -1,12 +1,12 @@
 #include "e.h"
 #include "e_mod_main.h"
 
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 # include <err.h>
 # include <sys/types.h>
 # include <sys/sysctl.h>
 
-#if defined(__OpenBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__)
 # include <sys/param.h>
 # include <sys/sensors.h>
 #endif
@@ -24,7 +24,7 @@ static Battery *bat = NULL;
 int
 _battery_sysctl_start(void)
 {
-# if defined(__OpenBSD__) || defined(__NetBSD__)
+# if defined(__OpenBSD__)
    int mib[] = {CTL_HW, HW_SENSORS, 0, 0, 0};
    int devn;
    struct sensordev snsrdev;
@@ -33,7 +33,7 @@ _battery_sysctl_start(void)
    size_t len;
 # endif
 
-# if defined(__OpenBSD__) || defined(__NetBSD__)
+# if defined(__OpenBSD__)
    for (devn = 0;; devn++) {
         mib[2] = devn;
         if (sysctl(mib, 3, &snsrdev, &sdlen, NULL, 0) == -1)
@@ -170,7 +170,7 @@ static int
 _battery_sysctl_battery_update()
 {
    double _time;
-# if defined(__OpenBSD__) || defined(__NetBSD__)
+# if defined(__OpenBSD__)
    double charge;
    struct sensor s;
    size_t slen = sizeof(struct sensor);
@@ -184,7 +184,7 @@ _battery_sysctl_battery_update()
        /* update the poller interval */
        ecore_poller_poller_interval_set(bat->poll,
                                         battery_config->poll_interval);
-# if defined(__OpenBSD__) || defined(__NetBSD__)
+# if defined(__OpenBSD__)
        charge = 0;
 
        /* last full capacity */
@@ -312,7 +312,7 @@ _battery_sysctl_battery_update()
 
    if (ac)
      {
-# if defined(__OpenBSD__) || defined(__NetBSD__)
+# if defined(__OpenBSD__)
        /* AC State */
        ac->mib[3] = 9;
        ac->mib[4] = 0;

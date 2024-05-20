$NetBSD$

* NetBSD's sysctl is different than in other BSD's,
* use upower backend

--- src/modules/battery/e_mod_main.h.orig	2023-12-23 16:08:09.000000000 +0000
+++ src/modules/battery/e_mod_main.h
@@ -123,7 +123,7 @@ void        _battery_device_update(void)
 int         _battery_udev_start(void);
 void        _battery_udev_stop(void);
 /* end e_mod_udev.c */
-#elif !defined __OpenBSD__ && !defined __DragonFly__ && !defined __FreeBSD__ && !defined __NetBSD__
+#elif !defined __OpenBSD__ && !defined __DragonFly__ && !defined __FreeBSD__
 /* in e_mod_dbus.c */
 int         _battery_upower_start(void);
 void        _battery_upower_stop(void);

$NetBSD$

* NetBSD's sysctl is different than in other BSD's,
* use upower backend

--- src/modules/battery/e_mod_main.h.orig	2020-05-31 18:22:37.502253800 +0000
+++ src/modules/battery/e_mod_main.h
@@ -53,7 +53,7 @@ struct _Config
    Eeze_Udev_Watch     *acwatch;
    Eeze_Udev_Watch     *batwatch;
 #endif
-#if defined HAVE_EEZE || defined __OpenBSD__ || defined __NetBSD__
+#if defined HAVE_EEZE || defined __OpenBSD__
    Eina_Bool            fuzzy;
    int                  fuzzcount;
 #endif
@@ -65,12 +65,12 @@ typedef struct _Ac_Adapter Ac_Adapter;
 struct _Battery
 {
    const char *udi;
-#if defined HAVE_EEZE || defined __OpenBSD__ || defined __DragonFly__ || defined __FreeBSD__ || defined __NetBSD__
+#if defined HAVE_EEZE || defined __OpenBSD__ || defined __DragonFly__ || defined __FreeBSD__
    Ecore_Poller *poll;
 #endif
    Eina_Bool present E_BITFIELD;
    Eina_Bool charging E_BITFIELD;
-#if defined HAVE_EEZE || defined __OpenBSD__ || defined __DragonFly__ || defined __FreeBSD__ || defined __NetBSD__
+#if defined HAVE_EEZE || defined __OpenBSD__ || defined __DragonFly__ || defined __FreeBSD__
    double last_update;
    double percent;
    double current_charge;
@@ -122,7 +122,7 @@ void _battery_device_update(void);
 int  _battery_udev_start(void);
 void _battery_udev_stop(void);
 /* end e_mod_udev.c */
-#elif !defined __OpenBSD__ && !defined __DragonFly__ && !defined __FreeBSD__ && !defined __NetBSD__
+#elif !defined __OpenBSD__ && !defined __DragonFly__ && !defined __FreeBSD__
 /* in e_mod_dbus.c */
 int _battery_upower_start(void);
 void _battery_upower_stop(void);

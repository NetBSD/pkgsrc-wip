$NetBSD$

* NetBSD's sysctl is different than in other BSD's,
* use upower backend

--- src/modules/battery/e_mod_main.c.orig	2020-05-31 18:22:37.502253800 +0000
+++ src/modules/battery/e_mod_main.c
@@ -366,7 +366,7 @@ _battery_config_updated(void)
      {
 #ifdef HAVE_EEZE
         ok = _battery_udev_start();
-#elif defined __OpenBSD__ || defined __DragonFly__ || defined __FreeBSD__ || defined __NetBSD__
+#elif defined __OpenBSD__ || defined __DragonFly__ || defined __FreeBSD__
         ok = _battery_sysctl_start();
 #else
         ok = _battery_upower_start();
@@ -736,7 +736,7 @@ e_modapi_init(E_Module *m)
    E_CONFIG_VAL(D, T, alert_timeout, INT);
    E_CONFIG_VAL(D, T, suspend_below, INT);
    E_CONFIG_VAL(D, T, force_mode, INT);
-#if defined HAVE_EEZE || defined __OpenBSD__ || defined __NetBSD__
+#if defined HAVE_EEZE || defined __OpenBSD__
    E_CONFIG_VAL(D, T, fuzzy, INT);
 #endif
    E_CONFIG_VAL(D, T, desktop_notifications, INT);
@@ -751,7 +751,7 @@ e_modapi_init(E_Module *m)
         battery_config->alert_timeout = 0;
         battery_config->suspend_below = 0;
         battery_config->force_mode = 0;
-#if defined HAVE_EEZE || defined __OpenBSD__ || defined __NetBSD__
+#if defined HAVE_EEZE || defined __OpenBSD__
         battery_config->fuzzy = 0;
 #endif
         battery_config->desktop_notifications = 0;
@@ -824,7 +824,7 @@ e_modapi_shutdown(E_Module *m EINA_UNUSE
 
 #ifdef HAVE_EEZE
    _battery_udev_stop();
-#elif defined (__OpenBSD__) || defined (__DragonFly__) || defined (__FreeBSD__) || defined (__NetBSD__)
+#elif defined (__OpenBSD__) || defined (__DragonFly__) || defined (__FreeBSD__)
    _battery_sysctl_stop();
 #else
    _battery_upower_stop();

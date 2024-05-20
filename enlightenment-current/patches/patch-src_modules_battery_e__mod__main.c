$NetBSD$

--- src/modules/battery/e_mod_main.c.orig	2023-12-23 16:08:09.000000000 +0000
+++ src/modules/battery/e_mod_main.c
@@ -1051,7 +1051,7 @@ e_modapi_init(E_Module *m)
    E_CONFIG_VAL(D, T, alert_timeout, INT);
    E_CONFIG_VAL(D, T, suspend_below, INT);
    E_CONFIG_VAL(D, T, force_mode, INT);
-#if defined HAVE_EEZE || defined(__OpenBSD__)
+#if defined HAVE_EEZE || defined(__OpenBSD__) || defined(__NetBSD__)
    E_CONFIG_VAL(D, T, fuzzy, INT);
 #endif
    E_CONFIG_VAL(D, T, desktop_notifications, INT);
@@ -1066,7 +1066,7 @@ e_modapi_init(E_Module *m)
         battery_config->alert_timeout = 0;
         battery_config->suspend_below = 0;
         battery_config->force_mode = 0;
-#if defined HAVE_EEZE || defined(__OpenBSD__)
+#if defined HAVE_EEZE || defined(__OpenBSD__) || defined(__NetBSD__)
         battery_config->fuzzy = 0;
 #endif
         battery_config->desktop_notifications = 0;

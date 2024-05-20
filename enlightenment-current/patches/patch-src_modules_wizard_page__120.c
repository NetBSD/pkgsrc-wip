$NetBSD$

* Add NetBSD support
* Fix build without eeze on linux

--- src/modules/wizard/page_120.c.orig	2023-12-23 16:08:09.000000000 +0000
+++ src/modules/wizard/page_120.c
@@ -100,7 +100,7 @@ wizard_page_show(E_Wizard_Page *pg EINA_
    Eina_List *tempdevs = NULL;
 #endif
    int hav_temperature = 0;
-#if defined (__FreeBSD__) || defined (__OpenBSD__)
+#if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
    // figure out on bsd if we have temp sensors
 #else
    const char *sensor_path[] = {
@@ -113,10 +113,10 @@ wizard_page_show(E_Wizard_Page *pg EINA_
       "/sys/devices/platform/thinkpad_hwmon/temp1_input",
       NULL
    };
+#endif

 #ifdef HAVE_EEZE
    tempdevs = eeze_udev_find_by_type(EEZE_UDEV_TYPE_IS_IT_HOT_OR_IS_IT_COLD_SENSOR, NULL);
-#endif
    if (tempdevs && (eina_list_count(tempdevs)))
      hav_temperature = 1;
    else

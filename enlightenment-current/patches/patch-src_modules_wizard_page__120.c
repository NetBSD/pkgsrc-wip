$NetBSD$

* Add NetBSD support
* Fix build without eeze on linux

--- src/modules/wizard/page_120.c.orig	2020-11-24 12:08:02.226764880 +0000
+++ src/modules/wizard/page_120.c
@@ -34,7 +34,7 @@
    }
  */
 
-#if defined (__FreeBSD__) || defined (__OpenBSD__)
+#if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
 #else
 static Eina_List *
 _wizard_temperature_get_bus_files(const char *bus)
@@ -100,7 +100,7 @@ wizard_page_show(E_Wizard_Page *pg EINA_
    Eina_List *tempdevs = NULL;
 #endif
    int hav_temperature = 0;
-#if defined (__FreeBSD__) || defined (__OpenBSD__)
+#if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
    // figure out on bsd if we have temp sensors
 #else
    const char *sensor_path[] = {
@@ -116,11 +116,11 @@ wizard_page_show(E_Wizard_Page *pg EINA_
 
 #ifdef HAVE_EEZE
    tempdevs = eeze_udev_find_by_type(EEZE_UDEV_TYPE_IS_IT_HOT_OR_IS_IT_COLD_SENSOR, NULL);
-#endif
    if (tempdevs && (eina_list_count(tempdevs)))
      hav_temperature = 1;
    else
      {
+#endif
         int i = 0;
 
         while(sensor_path[i] != NULL)
@@ -170,8 +170,10 @@ wizard_page_show(E_Wizard_Page *pg EINA_
                   eina_list_free(therms);
                }
           }
+#ifdef HAVE_EEZE
      }
 #endif
+#endif
    if (!hav_temperature)
      {
         E_Config_Module *em;

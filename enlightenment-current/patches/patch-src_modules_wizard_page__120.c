$NetBSD$

* Add NetBSD support

--- src/modules/wizard/page_120.c.orig	2020-05-17 19:40:56.441332600 +0000
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

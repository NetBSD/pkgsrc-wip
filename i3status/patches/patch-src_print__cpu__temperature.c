$NetBSD: patch-src_print__cpu__temperature.c,v 1.2 2011/08/01 15:48:54 pallegra Exp $

--- src/print_cpu_temperature.c.orig	2011-07-21 21:11:48.000000000 +0000
+++ src/print_cpu_temperature.c
@@ -25,10 +25,12 @@ void print_cpu_temperature_info(int zone
         const char *walk;
         static char buf[16];
 
+#if defined(LINUX) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
         if (path == NULL) {
                 asprintf(&thermal_zone, THERMAL_ZONE, zone);
                 path = thermal_zone;
         }
+#endif
 
         for (walk = format; *walk != '\0'; walk++) {
                 if (*walk != '%') {

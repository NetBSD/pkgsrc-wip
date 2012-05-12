$NetBSD: patch-src_conky.c,v 1.6 2012/05/12 12:49:49 imilh Exp $

--- src/conky.c.orig	2012-05-03 21:22:21.000000000 +0000
+++ src/conky.c
@@ -65,7 +65,7 @@
 #include <fcntl.h>
 #include <getopt.h>
 #ifdef NCURSES
-#include <ncurses.h>
+#include <curses.h>
 #endif
 #ifdef XOAP
 #include <libxml/parser.h>
@@ -117,16 +117,22 @@
 #include "freebsd.h"
 #elif defined(__OpenBSD__)
 #include "openbsd.h"
+#elif defined(__NetBSD__)
+#include "netbsd.h"
 #endif
 
+
 #if defined(__FreeBSD_kernel__)
 #include <bsd/bsd.h>
 #endif
 
 /* FIXME: apm_getinfo is unused here. maybe it's meant for common.c */
 #if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
-		|| defined(__OpenBSD__)) && (defined(i386) || defined(__i386__))
+	|| defined(__OpenBSD__)) && (defined(i386) || defined(__i386__))	\
+	|| defined(__NetBSD__)
+#ifndef __NetBSD__
 int apm_getinfo(int fd, apm_info_t aip);
+#endif
 char *get_apm_adapter(void);
 char *get_apm_battery_life(void);
 char *get_apm_battery_time(void);
@@ -784,7 +790,7 @@ void generate_text_internal(char *p, int
 			OBJ(read_tcp) {
 				print_read_tcp(obj, p, p_max_size);
 			}
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 			OBJ(acpitemp) {
 				temp_print(p, p_max_size, get_acpi_temperature(obj->data.i), TEMP_CELSIUS);
 			}
@@ -799,7 +805,7 @@ void generate_text_internal(char *p, int
 			OBJ(freq_g) {
 				static int ok = 1;
 				if (ok) {
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 					ok = get_freq(p, p_max_size, "%'.2f", 1000,
 							obj->data.i);
 #else
@@ -846,7 +852,7 @@ void generate_text_internal(char *p, int
 
 #endif /* __linux__ */
 
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__)
 			OBJ(acpifan) {
 				get_acpi_fan(p, p_max_size);
 			}
@@ -1015,13 +1021,11 @@ void generate_text_internal(char *p, int
 				get_powerbook_batt_info(p, p_max_size, obj->data.i);
 			}
 #endif /* __linux__ */
-#if (defined(__FreeBSD__) || defined(__linux__))
 			OBJ(if_up) {
 				if (!interface_up(obj)) {
 					DO_JUMP;
 				}
 			}
-#endif
 #ifdef __OpenBSD__
 			OBJ(obsd_sensors_temp) {
 				print_obsd_sensors_temp(obj, p, p_max_size);
@@ -1899,7 +1903,7 @@ void generate_text_internal(char *p, int
 			}
 #endif /* __linux__ */
 #if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
-		|| defined(__OpenBSD__)) && (defined(i386) || defined(__i386__))
+	|| defined(__OpenBSD__)) && (defined(i386) || defined(__i386__))
 			OBJ(apm_adapter) {
 				char *msg;
 
@@ -5680,6 +5684,13 @@ void initialisation(int argc, char **arg
 	}
 	pthread_mutex_init(&kvm_proc_mutex, NULL);
 #endif
+#if defined(__NetBSD__)
+	if ((kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, NULL)) == NULL)
+		CRIT_ERR(NULL, NULL, "cannot read kvm");
+
+	/* open the sysmon fd */
+	sysmon_open();
+#endif
 
 	while (1) {
 		int c = getopt_long(argc, argv, getopt_string, longopts, NULL);
@@ -5960,9 +5971,13 @@ int main(int argc, char **argv)
 	curl_global_cleanup();
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 	kvm_close(kd);
+#ifndef __NetBSD__
 	pthread_mutex_destroy(&kvm_proc_mutex);
+#else
+	sysmon_close();
+#endif
 #endif
 
 	return 0;

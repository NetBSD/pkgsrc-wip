$NetBSD: patch-src_conky.c,v 1.4 2012/05/07 08:45:17 imilh Exp $

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
@@ -117,8 +117,11 @@
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
@@ -784,7 +787,7 @@ void generate_text_internal(char *p, int
 			OBJ(read_tcp) {
 				print_read_tcp(obj, p, p_max_size);
 			}
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 			OBJ(acpitemp) {
 				temp_print(p, p_max_size, get_acpi_temperature(obj->data.i), TEMP_CELSIUS);
 			}
@@ -799,7 +802,7 @@ void generate_text_internal(char *p, int
 			OBJ(freq_g) {
 				static int ok = 1;
 				if (ok) {
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 					ok = get_freq(p, p_max_size, "%'.2f", 1000,
 							obj->data.i);
 #else
@@ -846,7 +849,7 @@ void generate_text_internal(char *p, int
 
 #endif /* __linux__ */
 
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 			OBJ(acpifan) {
 				get_acpi_fan(p, p_max_size);
 			}
@@ -3493,6 +3496,9 @@ static void main_loop(void)
 	next_update_time = get_time();
 	info.looped = 0;
 	while (terminate == 0 && (total_run_times == 0 || info.looped < total_run_times)) {
+#ifdef __NetBSD__
+		update_interval = update_interval_old;
+#else
 		if(update_interval_bat != NOBATTERY && update_interval_bat != update_interval_old) {
 			char buf[max_user_text];
 
@@ -3503,6 +3509,7 @@ static void main_loop(void)
 				update_interval = update_interval_old;
 			}
 		}
+#endif
 		info.looped++;
 
 #ifdef SIGNAL_BLOCKING
@@ -5680,6 +5687,10 @@ void initialisation(int argc, char **arg
 	}
 	pthread_mutex_init(&kvm_proc_mutex, NULL);
 #endif
+#if defined(__NetBSD__)
+	if ((kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, NULL)) == NULL)
+		CRIT_ERR(NULL, NULL, "cannot read kvm");
+#endif
 
 	while (1) {
 		int c = getopt_long(argc, argv, getopt_string, longopts, NULL);
@@ -5960,10 +5971,12 @@ int main(int argc, char **argv)
 	curl_global_cleanup();
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 	kvm_close(kd);
+#ifndef __NetBSD__
 	pthread_mutex_destroy(&kvm_proc_mutex);
 #endif
+#endif
 
 	return 0;
 

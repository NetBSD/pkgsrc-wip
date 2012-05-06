$NetBSD: patch-src_conky.c,v 1.3 2012/05/06 10:46:15 imilh Exp $

NetBSD's curses are good enough, use portable header file name.

--- src/conky.c.orig	2010-10-05 21:29:36.000000000 +0000
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
@@ -804,7 +807,7 @@ void generate_text_internal(char *p, int
 			OBJ(read_tcp) {
 				print_read_tcp(obj, p, p_max_size);
 			}
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 			OBJ(acpitemp) {
 				temp_print(p, p_max_size, get_acpi_temperature(obj->data.i), TEMP_CELSIUS);
 			}
@@ -819,7 +822,7 @@ void generate_text_internal(char *p, int
 			OBJ(freq_g) {
 				static int ok = 1;
 				if (ok) {
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 					ok = get_freq(p, p_max_size, "%'.2f", 1000,
 							obj->data.i);
 #else
@@ -866,7 +869,7 @@ void generate_text_internal(char *p, int
 
 #endif /* __linux__ */
 
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 			OBJ(acpifan) {
 				get_acpi_fan(p, p_max_size);
 			}
@@ -3531,6 +3534,9 @@ static void main_loop(void)
 	next_update_time = get_time();
 	info.looped = 0;
 	while (terminate == 0 && (total_run_times == 0 || info.looped < total_run_times)) {
+#ifdef __NetBSD__
+		update_interval = update_interval_old;
+#else
 		if(update_interval_bat != NOBATTERY && update_interval_bat != update_interval_old) {
 			char buf[max_user_text];
 
@@ -3541,6 +3547,7 @@ static void main_loop(void)
 				update_interval = update_interval_old;
 			}
 		}
+#endif
 		info.looped++;
 
 #ifdef SIGNAL_BLOCKING
@@ -5717,6 +5724,10 @@ void initialisation(int argc, char **arg
 		CRIT_ERR(NULL, NULL, "cannot read kvm");
 	}
 #endif
+#if defined(__NetBSD__)
+	if ((kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, NULL)) == NULL)
+		CRIT_ERR(NULL, NULL, "cannot read kvm");
+#endif
 
 	while (1) {
 		int c = getopt_long(argc, argv, getopt_string, longopts, NULL);
@@ -5997,7 +6008,7 @@ int main(int argc, char **argv)
 	curl_global_cleanup();
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 	kvm_close(kd);
 #endif
 

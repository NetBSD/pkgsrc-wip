$NetBSD: patch-src_conky.c,v 1.2 2012/05/04 10:57:24 imilh Exp $

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
@@ -866,7 +866,7 @@ void generate_text_internal(char *p, int
 
 #endif /* __linux__ */
 
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 			OBJ(acpifan) {
 				get_acpi_fan(p, p_max_size);
 			}
@@ -3531,6 +3531,9 @@ static void main_loop(void)
 	next_update_time = get_time();
 	info.looped = 0;
 	while (terminate == 0 && (total_run_times == 0 || info.looped < total_run_times)) {
+#ifdef __NetBSD__
+		update_interval = update_interval_old;
+#else
 		if(update_interval_bat != NOBATTERY && update_interval_bat != update_interval_old) {
 			char buf[max_user_text];
 
@@ -3541,6 +3544,7 @@ static void main_loop(void)
 				update_interval = update_interval_old;
 			}
 		}
+#endif
 		info.looped++;
 
 #ifdef SIGNAL_BLOCKING

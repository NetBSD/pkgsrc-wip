$NetBSD$

Surround some Linux-specific features with #ifdefs.

--- src/intern_blks/ya_intern.c.orig	2016-04-08 21:27:30.000000000 +0000
+++ src/intern_blks/ya_intern.c
@@ -9,7 +9,9 @@
 #include "yabar.h"
 
 void ya_int_date(ya_block_t * blk);
+#ifdef __linux__
 void ya_int_uptime(ya_block_t * blk);
+#endif
 void ya_int_memory(ya_block_t * blk);
 void ya_int_thermal(ya_block_t *blk);
 void ya_int_brightness(ya_block_t *blk);
@@ -20,7 +22,9 @@ void ya_int_network(ya_block_t *blk);
 
 struct reserved_blk ya_reserved_blks[YA_INTERNAL_LEN] = { 
 	{"YABAR_DATE", ya_int_date},
+#ifdef __linux__
 	{"YABAR_UPTIME", ya_int_uptime},
+#endif
 	{"YABAR_THERMAL", ya_int_thermal},
 	{"YABAR_BRIGHTNESS", ya_int_brightness},
 	{"YABAR_BANDWIDTH", ya_int_bandwidth},
@@ -70,7 +74,8 @@ void ya_int_date(ya_block_t * blk) {
 	}
 }
 
-#include <sys/sysinfo.h>
+#ifdef __linux__
+#  include <sys/sysinfo.h>
 
 void ya_int_uptime(ya_block_t *blk) {
 	struct sysinfo ya_sysinfo;
@@ -93,7 +98,7 @@ void ya_int_uptime(ya_block_t *blk) {
 		sleep(blk->sleep);
 	}
 }
-
+#endif
 
 void ya_int_thermal(ya_block_t *blk) {
 	FILE *tfile;
@@ -401,7 +406,9 @@ void ya_int_diskio(ya_block_t *blk) {
 #define _GNU_SOURCE
 #include <sys/socket.h>
 #include <ifaddrs.h>
-#include <linux/if_link.h>
+#ifdef __linux__
+#  include <linux/if_link.h>
+#endif
 #include <arpa/inet.h>
 #include <netdb.h>
 

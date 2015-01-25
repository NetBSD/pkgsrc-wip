$NetBSD: patch-openpgm_pgm_time.c,v 1.1 2015/01/25 09:13:36 obache Exp $

--- openpgm/pgm/time.c.orig	2012-12-04 02:57:22.000000000 +0000
+++ openpgm/pgm/time.c
@@ -163,7 +163,7 @@ static pgm_time_t		pgm_rtc_update (void)
 #ifdef HAVE_RDTSC
 #	include <stdio.h>
 #	include <string.h>
-#	if defined(__APPLE__) || defined(__FreeBSD__)
+#	if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #		include <sys/sysctl.h>
 #	elif defined(__sun)
 #		include <kstat.h>
@@ -441,7 +441,7 @@ pgm_time_init (
 		if (0 == sysctlbyname ("hw.cpufrequency", &cpufrequency, &len, NULL, 0)) {
 			tsc_khz = (uint_fast32_t)(cpufrequency / 1000);
 		}
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 /* frequency in Mhz */
 		unsigned long clockrate;
 		size_t len;

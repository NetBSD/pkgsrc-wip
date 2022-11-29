$NetBSD$

* Improve CPU model name detection on NetBSD.
* Fix uptime count on NetBSD and re-enable it.

--- bsdfetch.c.orig	2022-11-23 13:22:36.000000000 +0000
+++ bsdfetch.c
@@ -17,19 +17,20 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
-#include <time.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/utsname.h>
 #include <dlfcn.h>
 #if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/time.h>
 #include <sys/vmmeter.h>
 #include <vm/vm_param.h>
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/time.h>
 #endif
 #ifdef __OpenBSD__
 #include "sysctlbyname.h"
-#include <sys/time.h>
 #include <sys/sensors.h>
 #endif
 
@@ -103,7 +104,6 @@ static void get_user() {
 
 static void get_cpu() {
 	size_t num_cpu_size = 0;
-	size_t cpu_type_size = 0;
 	uint num_cpu = 0;
 	char cpu_type[200] = {0};
 	char tmp[100] = {0};
@@ -113,11 +113,24 @@ static void get_cpu() {
 	if(sysctlbyname("hw.ncpu", &num_cpu, &num_cpu_size, NULL, 0) == -1)
 		die(errno, __LINE__);
 
-	cpu_type_size = sizeof(char) * 200;
+#if defined(__NetBSD__)
+	FILE *fc = NULL;
 
-	if(sysctlbyname("hw.model", &cpu_type, &cpu_type_size, NULL, 0) == -1)
+	fc = popen("awk 'BEGIN{FS=\":\"} /model name/ { print $2; exit }' "
+                   "/proc/cpuinfo | sed -e 's/ @//' -e 's/^ *//g' -e 's/ *$//g' "
+                   "| head -1 | tr -d '\\n'",
+                   "r");
+	if (fc == NULL)
 		die(errno, __LINE__);
 
+	fgets(cpu_type, sizeof(cpu_type), fc);
+	pclose(fc);
+#else
+	size_t cpu_type_size = 0;
+	cpu_type_size = sizeof(char) * 200;
+	if(sysctlbyname("hw.model", &cpu_type, &cpu_type_size, NULL, 0) == -1)
+		die(errno, __LINE__);
+#endif
 	show("CPU", cpu_type);
 
 	_SILENT sprintf(tmp, "%d", num_cpu);
@@ -284,10 +297,8 @@ static void get_uptime() {
 	int minutes = 0;
 	struct timespec t;
 
-// NetBSD kernel doesn't implement CLOCK_UPTIME, to assume we've we'll set CLOCK_UPTIME to CLOCK_REALTIME
-// More easily we can also use value 5 instead CLOCK_UPTIME, since it's only for FreeBSD
 #ifndef CLOCK_UPTIME
-#define CLOCK_UPTIME 0
+#define CLOCK_UPTIME CLOCK_MONOTONIC 
 #endif
 	ret = clock_gettime(CLOCK_UPTIME, &t);
 	if(ret == -1)
@@ -413,9 +424,7 @@ int main(int argc, char **argv) {
 	get_shell();
 	get_user();
 	get_packages();
-#ifndef __NetBSD__
 	get_uptime();
-#endif
 	get_memory();
 	get_loadavg();
 	get_cpu();

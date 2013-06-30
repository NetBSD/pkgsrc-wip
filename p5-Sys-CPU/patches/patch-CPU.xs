$NetBSD: patch-CPU.xs,v 1.1 2013/06/30 13:43:59 noud4 Exp $

thanks to
http://svnweb.freebsd.org/ports/head/devel/p5-Sys-Cpu/files/patch-CPU.xs?revision=300896&view=markup

--- CPU.xs.orig	2012-11-13 04:47:34.000000000 +0000
+++ CPU.xs
@@ -40,6 +40,11 @@
  #define _have_cpu_clock
  #define _have_cpu_type
 #endif
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#include <sys/sysctl.h>
+#define _have_cpu_type
+#define _have_cpu_clock
+#endif
 #ifdef WINDOWS
 /* Registry Functions */
 
@@ -329,6 +334,19 @@ CODE:
     int value = proc_cpuinfo_clock();
     if (value) clock = value;
 #endif
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+    size_t len = sizeof(clock);
+    char const *name;
+
+    if(sysctlbyname("hw.clockrate", NULL, &len, NULL, 0) == 0)
+        name = "hw.clockrate";
+    else if(sysctlbyname("machdep.powernow.frequency.current", NULL, &len, NULL, 0) == 0)
+        name = "machdep.powernow.frequency.current";
+    else if(sysctlbyname("machdep.est.frequency.current", NULL, &len, NULL, 0) == 0)
+        name = "machdep.est.frequency.current";
+
+    sysctlbyname(name, &clock, &len, NULL, 0);
+#endif
 #ifdef WINDOWS
     char *clock_str = malloc(MAX_IDENT_SIZE);
     /*!! untested !!*/
@@ -366,6 +375,12 @@ cpu_type()
 CODE:
 {
-    char *value = NULL;
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+    char *value = malloc(MAX_IDENT_SIZE);
+    size_t len = MAX_IDENT_SIZE;
+    sysctlbyname("hw.model", value, &len, NULL, 0);
+#else
+    char *value = NULL;
+#endif
 #ifdef __linux__
 #if defined __s390__ || defined __s390x__
     value = processor_machine_field (proc_cpuinfo_field ("processor") );

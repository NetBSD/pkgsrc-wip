$NetBSD$

adjust FreeBSD code for NetBSD

--- src/jdk.management/bsd/native/libmanagement_ext/UnixOperatingSystem.c.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/jdk.management/bsd/native/libmanagement_ext/UnixOperatingSystem.c	2021-06-11 13:52:54.750098914 -0400
@@ -29,7 +29,19 @@
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/time.h>
+#ifdef __FreeBSD__
 #include <sys/user.h>
+#define CPUSTATES_TYPE long
+#define MIB_KERN_PROC KERN_PROC
+#define MIBSIZE 4
+#endif
+#ifdef __NetBSD__
+#include <sched.h>
+#define CPUSTATES_TYPE uint64_t
+#define kinfo_proc kinfo_proc2
+#define MIB_KERN_PROC KERN_PROC2
+#define MIBSIZE 6
+#endif
 #include <unistd.h>
 
 #include "jvm.h"
@@ -38,14 +50,14 @@
 Java_com_sun_management_internal_OperatingSystemImpl_getCpuLoad0
 (JNIEnv *env, jobject dummy)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
     /* This is based on the MacOS X implementation */
 
     static jlong last_used  = 0;
     static jlong last_total = 0;
 
     /* Load CPU times */
-    long cp_time[CPUSTATES];
+    CPUSTATES_TYPE cp_time[CPUSTATES];
     size_t len = sizeof(cp_time);
     if (sysctlbyname("kern.cp_time", &cp_time, &len, NULL, 0) == -1) {
         return -1.;
@@ -92,7 +104,7 @@
 Java_com_sun_management_internal_OperatingSystemImpl_getProcessCpuLoad0
 (JNIEnv *env, jobject dummy)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
     /* This is based on the MacOS X implementation */
 
     static jlong last_task_time = 0;
@@ -100,13 +112,17 @@
 
     struct timeval now;
     struct kinfo_proc kp;
-    int mib[4];
+    int mib[MIBSIZE];
     size_t len = sizeof(struct kinfo_proc);
 
     mib[0] = CTL_KERN;
-    mib[1] = KERN_PROC;
+    mib[1] = MIB_KERN_PROC;
     mib[2] = KERN_PROC_PID;
     mib[3] = getpid();
+#ifdef __NetBSD__
+    mib[4] = sizeof(kp);
+    mib[5] = 1;
+#endif
 
     if (sysctl(mib, 4, &kp, &len, NULL, 0) == -1) {
         return -1.;
@@ -118,8 +134,16 @@
 
     jint ncpus      = JVM_ActiveProcessorCount();
     jlong time      = TIME_VALUE_TO_MICROSECONDS(now) * ncpus;
+#ifdef __FreeBSD__
     jlong task_time = TIME_VALUE_TO_MICROSECONDS(kp.ki_rusage.ru_utime) +
                       TIME_VALUE_TO_MICROSECONDS(kp.ki_rusage.ru_stime);
+#endif
+#ifdef __NetBSD__
+    jlong task_time = (jlong)kp.p_uutime_sec * 1000 * 1000 +
+	kp.p_uutime_usec +
+	(jlong)kp.p_ustime_sec * 1000 * 1000 +
+	kp.p_ustime_usec;
+#endif
 
     if ((last_task_time == 0) || (last_time == 0)) {
         // First call, just set the last values.
@@ -159,7 +183,7 @@
 Java_com_sun_management_internal_OperatingSystemImpl_getHostConfiguredCpuCount0
 (JNIEnv *env, jobject mbean)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
     return JVM_ActiveProcessorCount();
 #else
     // Not implemented yet

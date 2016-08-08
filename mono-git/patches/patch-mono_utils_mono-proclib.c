$NetBSD$

--- mono/utils/mono-proclib.c.orig	2016-05-07 13:14:36.000000000 +0000
+++ mono/utils/mono-proclib.c
@@ -48,6 +48,10 @@
 #    define kinfo_starttime_member kp_proc.p_starttime
 #    define kinfo_pid_member kp_proc.p_pid
 #    define kinfo_name_member kp_proc.p_comm
+#elif defined(__NetBSD__)
+#    define kinfo_starttime_member p_ustart_sec
+#    define kinfo_pid_member p_pid
+#    define kinfo_name_member p_comm
 #elif defined(__OpenBSD__)
 // Can not figure out how to get the proc's start time on OpenBSD
 #    undef kinfo_starttime_member 
@@ -317,8 +321,13 @@ mono_process_get_times (gpointer pid, gi
 		{
 			KINFO_PROC processi;
 
-			if (sysctl_kinfo_proc (pid, &processi))
+			if (sysctl_kinfo_proc (pid, &processi)) {
+#if defined(__NetBSD__)
+				*start_time = (gint64)processi.kinfo_starttime_member;
+#else
 				*start_time = mono_100ns_datetime_from_timeval (processi.kinfo_starttime_member);
+#endif
+			}
 		}
 #endif
 

$Id: patch-cgminer.c,v 1.1 2014/10/24 14:42:12 noud4 Exp $

i do not know if the below is correct.

--- cgminer.c.orig	2014-10-24 13:56:34.000000000 +0000
+++ cgminer.c
@@ -4525,7 +4525,11 @@ static void hashmeter(int thr_id, struct
 
 	local_secs = (double)total_diff.tv_sec + ((double)total_diff.tv_usec / 1000000.0);
 	decay_time(&rolling, local_mhashes_done / local_secs);
+#ifdef __NetBSD__
+	global_hashrate = round(rolling) * 1000000;
+#else
 	global_hashrate = roundl(rolling) * 1000000;
+#endif
 
 	timersub(&total_tv_end, &total_tv_start, &total_diff);
 	total_secs = (double)total_diff.tv_sec +

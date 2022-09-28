$NetBSD$

Fix time types (sizes).

--- src/zm_utils.cpp.orig	2018-12-08 14:22:36.000000000 +0000
+++ src/zm_utils.cpp
@@ -397,7 +397,7 @@ char *timeval_to_string( struct timeval 
   nowtime = tv.tv_sec;
   nowtm = localtime(&nowtime);
   strftime(tmbuf, sizeof tmbuf, "%Y-%m-%d %H:%M:%S", nowtm);
-  snprintf(buf, sizeof buf, "%s.%06ld", tmbuf, tv.tv_usec);
+  snprintf(buf, sizeof buf, "%s.%06jd", tmbuf, (intmax_t) tv.tv_usec);
   return buf;
 }
 

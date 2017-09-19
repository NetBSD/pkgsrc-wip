$NetBSD$

--- adb/adb_trace.h.orig	2017-06-27 22:39:52.000000000 +0000
+++ adb/adb_trace.h
@@ -50,9 +50,12 @@ enum AdbTrace {
         LOG(INFO)
 
 // You must define TRACE_TAG before using this macro.
+#ifdef ADB_HOST
+#define D(...) /*nothing*/
+#else
 #define D(...) \
     VLOG(TRACE_TAG) << android::base::StringPrintf(__VA_ARGS__)
-
+#endif
 
 extern int adb_trace_mask;
 void adb_trace_init(char**);

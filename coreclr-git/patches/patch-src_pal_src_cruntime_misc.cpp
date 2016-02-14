$NetBSD$

--- src/pal/src/cruntime/misc.cpp.orig	2016-02-06 02:05:27.000000000 +0000
+++ src/pal/src/cruntime/misc.cpp
@@ -260,6 +260,30 @@ PAL_rand(void)
 }
 
 
+/*++
+Function:
+
+   time
+
+See MSDN for more details.
+--*/
+PAL_time_t
+__cdecl 
+PAL_time(PAL_time_t *tloc)
+{
+    time_t result;
+
+    PERF_ENTRY(time);
+    ENTRY( "time( tloc=%p )\n",tloc );
+
+    result = time(tloc);
+
+    LOGEXIT( "time returning %#lx\n",result );
+    PERF_EXIT(time);
+    return result;
+}
+
+
 PALIMPORT 
 void __cdecl 
 PAL_qsort(void *base, size_t nmemb, size_t size, 

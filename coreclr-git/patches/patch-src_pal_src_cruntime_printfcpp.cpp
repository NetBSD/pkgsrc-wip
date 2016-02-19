$NetBSD$

--- src/pal/src/cruntime/printfcpp.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/cruntime/printfcpp.cpp
@@ -1068,7 +1068,18 @@ Parameters:
 
 int __cdecl PAL__vsnprintf(LPSTR Buffer, size_t Count, LPCSTR Format, va_list ap)
 {
-    return CoreVsnprintf(InternalGetCurrentThread(), Buffer, Count, Format, ap);
+    LONG Length;
+
+    PERF_ENTRY(PAL__vsnprintf);
+    ENTRY("PAL__vsnprintf (buffer=%p, count=%d, format=%p (%s), argptr=%p)\n",
+          Buffer, Count, Format, Format, ap);
+
+    Length = CoreVsnprintf(InternalGetCurrentThread(), Buffer, Count, Format, ap);
+
+    LOGEXIT("PAL__vsnprintf returns int %d\n", Length);
+    PERF_EXIT(PAL__vsnprintf);
+
+    return Length;
 }
 
 /*******************************************************************************

$NetBSD$

--- src/pal/src/cruntime/printf.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/cruntime/printf.cpp
@@ -1624,35 +1624,6 @@ PAL_vsprintf(char *buffer, 
 
 /*++
 Function:
-  _vsnprintf
-
-See MSDN doc.
---*/
-int 
-__cdecl 
-_vsnprintf(char *buffer, 
-           size_t count, 
-           const char *format, 
-           va_list argptr)
-{
-    LONG Length;
-
-    PERF_ENTRY(_vsnprintf);
-    ENTRY("_vsnprintf (buffer=%p, count=%d, format=%p (%s), argptr=%p)\n", 
-          buffer, count, format, format, argptr);
-
-    Length = PAL__vsnprintf(buffer, count, format, argptr);
-
-    LOGEXIT("_vsnprintf returns int %d\n", Length);
-    PERF_EXIT(_vsnprintf);
-
-    return Length;
-}
-
-
-
-/*++
-Function:
   PAL_vswprintf
 
 See MSDN doc.
@@ -1785,4 +1756,3 @@ static int SscanfFloatCheckExponent(LPCS
     return ret;
 }
 #endif // SSCANF_CANNOT_HANDLE_MISSING_EXPONENT
-

$NetBSD$

--- src/pal/src/cruntime/printf.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/cruntime/printf.cpp
@@ -45,6 +45,7 @@ static int SscanfFloatCheckExponent(LPCS
                                       void * voidPtr, int * pn);
 #endif // SSCANF_CANNOT_HANDLE_MISSING_EXPONENT
 
+
 /*******************************************************************************
 Function:
   Internal_AddPaddingA
@@ -295,7 +296,7 @@ wsprintfA(
     ENTRY("wsprintfA (buffer=%p, format=%p (%s))\n", buffer, format, format);
 
     va_start(ap, format);
-    Length = PAL__vsnprintf(buffer, 1024, format, ap);
+    Length = InternalVsnprintf(CorUnix::InternalGetCurrentThread(), buffer, 1024, format, ap);
     va_end(ap);
 
     LOGEXIT("wsprintfA returns int %d\n", Length);
@@ -354,7 +355,7 @@ _snprintf(
           buffer, (unsigned long) count, format, format);
 
     va_start(ap, format);
-    Length = PAL__vsnprintf(buffer, count, format, ap);
+    Length = InternalVsnprintf(CorUnix::InternalGetCurrentThread(), buffer, count, format, ap);
     va_end(ap);
 
     LOGEXIT("_snprintf returns int %d\n", Length);
@@ -1529,7 +1530,7 @@ PAL_sprintf(
     ENTRY("PAL_sprintf (buffer=%p, format=%p (%s))\n", buffer, format, format);
 
     va_start(ap, format);
-    Length = PAL__vsnprintf(buffer, 0x7fffffff, format, ap);
+    Length = InternalVsnprintf(CorUnix::InternalGetCurrentThread(), buffer, 0x7fffffff, format, ap);
     va_end(ap);
 
     LOGEXIT("PAL_sprintf returns int %d\n", Length);
@@ -1613,7 +1614,7 @@ PAL_vsprintf(char *buffer, 
     ENTRY("PAL_vsprintf (buffer=%p, format=%p (%s), argptr=%p)\n", 
           buffer, format, format, argptr);
 
-    Length = PAL__vsnprintf(buffer, 0x7fffffff, format, argptr);
+    Length = InternalVsnprintf(CorUnix::InternalGetCurrentThread(), buffer, 0x7fffffff, format, argptr);
 
     LOGEXIT("PAL_vsprintf returns int %d\n", Length);
     PERF_EXIT(vsprintf);
@@ -1624,35 +1625,6 @@ PAL_vsprintf(char *buffer, 
 
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
@@ -1785,4 +1757,3 @@ static int SscanfFloatCheckExponent(LPCS
     return ret;
 }
 #endif // SSCANF_CANNOT_HANDLE_MISSING_EXPONENT
-

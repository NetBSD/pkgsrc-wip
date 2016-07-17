$NetBSD$

--- third_party/pdfium/fpdfsdk/javascript/JS_Value.cpp.orig	2016-06-24 01:03:59.000000000 +0000
+++ third_party/pdfium/fpdfsdk/javascript/JS_Value.cpp
@@ -590,11 +590,12 @@ CFX_WideString CJS_Date::ToString() cons
 }
 
 double _getLocalTZA() {
+  struct tm *lt;
   if (!FSDK_IsSandBoxPolicyEnabled(FPDF_POLICY_MACHINETIME_ACCESS))
     return 0;
   time_t t = 0;
   time(&t);
-  localtime(&t);
+  lt = localtime(&t);
 #if _MSC_VER >= 1900
   // In gcc and in Visual Studio prior to VS 2015 'timezone' is a global
   // variable declared in time.h. That variable was deprecated and in VS 2015
@@ -602,7 +603,11 @@ double _getLocalTZA() {
   long timezone = 0;
   _get_timezone(&timezone);
 #endif
+#if defined(__FreeBSD__)
+  return (double)(-(lt->tm_gmtoff * 1000));
+#else
   return (double)(-(timezone * 1000));
+#endif
 }
 
 int _getDaylightSavingTA(double d) {

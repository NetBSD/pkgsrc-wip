$NetBSD$

--- gdb/utils.h.orig	2017-09-11 11:24:05.000000000 +0000
+++ gdb/utils.h
@@ -349,10 +349,9 @@ extern void printf_filtered (const char 
 
 extern void printfi_filtered (int, const char *, ...) ATTRIBUTE_PRINTF (2, 3);
 
-extern void vprintf_unfiltered (const char *, va_list) ATTRIBUTE_PRINTF (1, 0);
+extern void vprintf_unfiltered (const char *, va_list);
 
-extern void vfprintf_unfiltered (struct ui_file *, const char *, va_list)
-  ATTRIBUTE_PRINTF (2, 0);
+extern void vfprintf_unfiltered (struct ui_file *, const char *, va_list);
 
 extern void fprintf_unfiltered (struct ui_file *, const char *, ...)
   ATTRIBUTE_PRINTF (2, 3);

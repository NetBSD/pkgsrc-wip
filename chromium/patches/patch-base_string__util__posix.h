$NetBSD: patch-base_string__util__posix.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/string_util_posix.h.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/string_util_posix.h
@@ -45,7 +45,12 @@ inline int strncmp16(const char16* s1, c
 inline int vswprintf(wchar_t* buffer, size_t size,
                      const wchar_t* format, va_list arguments) {
   DCHECK(IsWprintfFormatPortable(format));
+#if defined(OS_OPENBSD)
+  // OpenBSD does not have a wide-char equivalent
+  return ::vsnprintf((char *)buffer, size, (const char *)format, arguments);
+#else
   return ::vswprintf(buffer, size, format, arguments);
+#endif
 }
 
 }  // namespace base

$NetBSD$

--- adb/sysdeps.h.orig	2017-06-27 22:39:52.000000000 +0000
+++ adb/sysdeps.h
@@ -65,11 +65,16 @@
 #endif
 #endif
 
-#ifdef _WIN32
-
 // Clang-only nullability specifiers
+#ifndef _Nonnull
 #define _Nonnull
+#endif
+
+#ifndef _Nullable
 #define _Nullable
+#endif
+
+#ifdef _WIN32
 
 #include <ctype.h>
 #include <direct.h>
@@ -710,8 +715,10 @@ static __inline__ void __attribute__((no
 }
 
 static __inline__ int adb_thread_setname(const std::string& name) {
-#ifdef __APPLE__
+#if defined(__APPLE__)
     return pthread_setname_np(name.c_str());
+#elif defined(__NetBSD__)
+    return pthread_setname_np(pthread_self(), name.c_str(), NULL);
 #else
     const char *s = name.c_str();
 

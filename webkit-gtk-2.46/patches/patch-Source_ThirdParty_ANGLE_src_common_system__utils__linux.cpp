$NetBSD$

pthread_setname_np() has three arguments on NetBSD.

--- Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp.orig	2024-11-02 07:53:20.751740774 +0000
+++ Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp
@@ -56,6 +56,10 @@ void SetCurrentThreadName(const char *na
 {
     // There's a 15-character (16 including '\0') limit.  If the name is too big (and ERANGE is
     // returned), just ignore the name.
+#ifdef __NetBSD__
+    pthread_setname_np(pthread_self(), "%s", (void *)name);
+#else
     pthread_setname_np(pthread_self(), name);
+#endif
 }
 }  // namespace angle

$NetBSD$

Stash previous locale in a string on NetBSD.

--- src/libslic3r/LocalesUtils.hpp.orig	2022-08-19 14:41:23.000000000 +0000
+++ src/libslic3r/LocalesUtils.hpp
@@ -23,6 +23,8 @@ public:
 private:
 #ifdef _WIN32
     std::string m_orig_numeric_locale;
+#elif __NetBSD__
+    std::string m_original_locale;
 #else
     locale_t m_original_locale;
     locale_t m_new_locale;
@@ -49,7 +51,7 @@ inline void set_c_locales()
 #ifdef _WIN32
     _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
     std::setlocale(LC_ALL, "C");
-#else
+#elif __LINUX__ || __OpenBSD__
     // We are leaking some memory here, because the newlocale() produced memory will never be released.
     // This is not a problem though, as there will be a maximum one worker thread created per physical thread.
     uselocale(newlocale(
@@ -59,6 +61,8 @@ inline void set_c_locales()
         LC_ALL
 #endif
         , "C", nullptr));
+#elif __NetBSD__
+	setlocale(LC_ALL, "C");
 #endif
 }
 

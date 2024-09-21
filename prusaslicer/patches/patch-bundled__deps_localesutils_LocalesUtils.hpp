$NetBSD$

Stash previous locale in a string on NetBSD.

--- bundled_deps/localesutils/LocalesUtils.hpp.orig	2024-09-20 13:15:33.333280337 +0000
+++ bundled_deps/localesutils/LocalesUtils.hpp
@@ -27,6 +27,8 @@ public:
 private:
 #ifdef _WIN32
     std::string m_orig_numeric_locale;
+#elif __NetBSD__
+    std::string m_original_locale;
 #else
     locale_t m_original_locale;
     locale_t m_new_locale;
@@ -54,16 +56,18 @@ inline void set_c_locales()
 #ifdef _WIN32
     _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
     std::setlocale(LC_ALL, "C");
-#else
+#elif __APPLE__ || __linux__ || __OpenBSD__
     // We are leaking some memory here, because the newlocale() produced memory will never be released.
     // This is not a problem though, as there will be a maximum one worker thread created per physical thread.
     uselocale(newlocale(
 #ifdef __APPLE__
         LC_ALL_MASK
-#else // some Unix / Linux / BSD
+#elif __linux__ || __OpenBSD__
         LC_ALL
 #endif
         , "C", nullptr));
+#elif __NetBSD__
+	
 #endif
 }
 

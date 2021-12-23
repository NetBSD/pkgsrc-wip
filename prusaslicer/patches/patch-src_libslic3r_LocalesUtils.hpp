$NetBSD$

Stash previous locale in a string on NetBSD.

--- src/libslic3r/LocalesUtils.hpp.orig	2021-12-17 14:00:02.000000000 +0000
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

$NetBSD$

uselocale(3) is not found on NetBSD. Substitute setlocale(3) which is ugly
as it affects the whole process rather than a single thread.
See the following thread for rationale against uselocale(3):
https://mail-index.netbsd.org/tech-userlevel/2015/12/28/msg009546.html

--- bundled_deps/localesutils/LocalesUtils.cpp.orig	2024-09-20 13:38:59.616830457 +0000
+++ bundled_deps/localesutils/LocalesUtils.cpp
@@ -26,11 +26,14 @@ CNumericLocalesSetter::CNumericLocalesSe
     m_original_locale = uselocale((locale_t)0);
     m_new_locale = newlocale(LC_NUMERIC_MASK, "C", m_original_locale);
     uselocale(m_new_locale);
-#else // linux / BSD
+#elif __linux__ || __OpenBSD__
     m_original_locale = uselocale((locale_t)0);
     m_new_locale = duplocale(m_original_locale);
     m_new_locale = newlocale(LC_NUMERIC_MASK, "C", m_new_locale);
     uselocale(m_new_locale);
+#elif __NetBSD__
+    m_original_locale = setlocale(LC_NUMERIC, nullptr);
+    setlocale(LC_NUMERIC, "C");
 #endif
 }
 
@@ -40,9 +43,11 @@ CNumericLocalesSetter::~CNumericLocalesS
 {
 #ifdef _WIN32
     std::setlocale(LC_NUMERIC, m_orig_numeric_locale.data());
-#else
+#elif __APPLE__ || __LINUX__ || __OpenBSD__
     uselocale(m_original_locale);
     freelocale(m_new_locale);
+#elif __NetBSD__
+    setlocale(LC_NUMERIC, m_original_locale.c_str());
 #endif
 }
 

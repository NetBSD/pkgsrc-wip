$NetBSD$

uselocale(3) is not found on NetBSD. Substitute setlocale(3) which is ugly
as it affects the whole process rather than a single thread.
See the following thread for rationale against uselocale(3):
https://mail-index.netbsd.org/tech-userlevel/2015/12/28/msg009546.html

--- src/libslic3r/LocalesUtils.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/libslic3r/LocalesUtils.cpp
@@ -21,11 +21,14 @@ CNumericLocalesSetter::CNumericLocalesSe
     m_original_locale = uselocale((locale_t)0);
     m_new_locale = newlocale(LC_NUMERIC_MASK, "C", m_original_locale);
     uselocale(m_new_locale);
-#else // linux / BSD
+#elif __LINUX__ || __OpenBSD__
     m_original_locale = uselocale((locale_t)0);
     m_new_locale = duplocale(m_original_locale);
     m_new_locale = newlocale(LC_NUMERIC_MASK, "C", m_new_locale);
     uselocale(m_new_locale);
+#elif __NetBSD__
+    m_original_locale = setlocale(LC_NUMERIC, nullptr);
+    setlocale(LC_NUMERIC, "C");
 #endif
 }
 
@@ -35,9 +38,11 @@ CNumericLocalesSetter::~CNumericLocalesS
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
 

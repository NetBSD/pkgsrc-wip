$NetBSD$

 getauxval is linux specific but sys/auxv.h is not, solaris has it

--- src/corelib/global/qconfig-bootstrapped.h.orig	2021-04-01 08:27:54.537024937 +0000
+++ src/corelib/global/qconfig-bootstrapped.h
@@ -88,7 +88,11 @@
 #define QT_FEATURE_datetimeparser -1
 #define QT_FEATURE_easingcurve -1
 #define QT_FEATURE_etw -1
+#ifdef __linux__
 #define QT_FEATURE_getauxval (__has_include(<sys/auxv.h>) ? 1 : -1)
+#else
+#define QT_FEATURE_getauxval -1
+#endif
 #define QT_FEATURE_getentropy -1
 #define QT_NO_GEOM_VARIANT
 #define QT_FEATURE_hijricalendar -1

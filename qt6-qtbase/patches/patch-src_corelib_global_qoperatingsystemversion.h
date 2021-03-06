$NetBSD$

* set OStype enums for Free and NetBSD

* NetBSD is a defined on NetBSD systems so unset it, this is safe since
  code shouldn't even count on it being defined according to sys/param.h

--- src/corelib/global/qoperatingsystemversion.h.orig	2021-01-26 18:29:22.000000000 +0000
+++ src/corelib/global/qoperatingsystemversion.h
@@ -42,6 +42,10 @@
 #ifndef QOPERATINGSYSTEMVERSION_H
 #define QOPERATINGSYSTEMVERSION_H
 
+#ifdef NetBSD
+#undef NetBSD
+#endif
+
 QT_BEGIN_NAMESPACE
 
 class QString;
@@ -57,7 +61,9 @@ public:
         IOS,
         TvOS,
         WatchOS,
-        Android
+        Android,
+        FreeBSD,
+        NetBSD
     };
 
     static const QOperatingSystemVersion Windows7;
@@ -109,6 +115,10 @@ public:
         return WatchOS;
 #elif defined(Q_OS_ANDROID)
         return Android;
+#elif defined(Q_OS_FREEBSD)
+        return FreeBSD;
+#elif defined(Q_OS_NETBSD)
+        return NetBSD;
 #else
         return Unknown;
 #endif

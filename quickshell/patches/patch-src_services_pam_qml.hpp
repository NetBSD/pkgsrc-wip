$NetBSD$

--- src/services/pam/qml.hpp.orig	2026-09-19 13:06:46.919473226 +0000
+++ src/services/pam/qml.hpp
@@ -6,7 +6,7 @@
 #include <qtclasshelpermacros.h>
 #include <qthread.h>
 #include <qtmetamacros.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <security/pam_types.h>
 #else
 #include <security/_pam_types.h>

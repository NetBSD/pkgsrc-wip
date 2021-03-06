$NetBSD$

* set operatingsystem verson using uname on Free and NetBSD

--- src/corelib/global/qoperatingsystemversion.cpp.orig	2021-01-26 18:29:22.000000000 +0000
+++ src/corelib/global/qoperatingsystemversion.cpp
@@ -150,7 +150,7 @@ QT_BEGIN_NAMESPACE
 
     \sa currentType()
 */
-#if !defined(Q_OS_DARWIN) && !defined(Q_OS_WIN)
+#if !defined(Q_OS_DARWIN) && !defined(Q_OS_WIN) && !defined(Q_OS_FREEBSD) && !defined(Q_OS_NETBSD)
 QOperatingSystemVersion QOperatingSystemVersion::current()
 {
     QOperatingSystemVersion version;

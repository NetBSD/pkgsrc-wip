$NetBSD$

--- plugins/ProcessProperties/DialogProcessProperties.cpp.orig	2017-02-18 21:21:09.000000000 +0000
+++ plugins/ProcessProperties/DialogProcessProperties.cpp
@@ -35,7 +35,7 @@ along with this program.  If not, see <h
 #include <QStringListModel>
 #include <QUrl>
 
-#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 #include <link.h>
 #include <arpa/inet.h>
 #endif

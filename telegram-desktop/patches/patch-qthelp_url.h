$NetBSD$

--- Telegram/lib_base/base/qthelp_url.h.orig	2020-02-16 19:42:50.207614396 +0000
+++ Telegram/lib_base/base/qthelp_url.h
@@ -10,6 +10,8 @@
 #include <QtCore/QString>
 #include <QtCore/QRegularExpression>
 
+#include "base/base_pch.h"
+
 namespace qthelp {
 
 const QRegularExpression &RegExpDomain();

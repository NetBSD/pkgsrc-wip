$NetBSD: patch-src_plugins_platforminputcontexts_compose_generator_qtablegenerator.cpp,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

PR pkg/48553

--- src/qt/qtbase/src/plugins/platforminputcontexts/compose/generator/qtablegenerator.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtbase/src/plugins/platforminputcontexts/compose/generator/qtablegenerator.cpp
@@ -76,6 +76,10 @@ void TableGenerator::initPossibleLocatio
     // the QTCOMPOSE environment variable
     if (qEnvironmentVariableIsSet("QTCOMPOSE"))
         m_possibleLocations.append(QString::fromLocal8Bit(qgetenv("QTCOMPOSE")));
+#ifdef X11BASE
+    m_possibleLocations.append(QStringLiteral(X11BASE) + QStringLiteral("/share/X11/locale"));
+    m_possibleLocations.append(QStringLiteral(X11BASE) + QStringLiteral("/lib/X11/locale"));
+#endif
     m_possibleLocations.append(QStringLiteral("/usr/share/X11/locale"));
     m_possibleLocations.append(QStringLiteral("/usr/local/share/X11/locale"));
     m_possibleLocations.append(QStringLiteral("/usr/lib/X11/locale"));

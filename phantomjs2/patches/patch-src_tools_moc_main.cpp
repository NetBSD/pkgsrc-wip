$NetBSD: patch-src_tools_moc_main.cpp,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

--- src/qt/qtbase/src/tools/moc/main.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtbase/src/tools/moc/main.cpp
@@ -192,6 +192,8 @@ int runMoc(int argc, char **argv)
     Moc moc;
     pp.macros["Q_MOC_RUN"];
     pp.macros["__cplusplus"];
+    // rh#756395, https://bugreports.qt-project.org/browse/QTBUG-22829
+    pp.macros["BOOST_TT_HAS_OPERATOR_HPP_INCLUDED"];
 
     // Don't stumble over GCC extensions
     Macro dummyVariadicFunctionMacro;

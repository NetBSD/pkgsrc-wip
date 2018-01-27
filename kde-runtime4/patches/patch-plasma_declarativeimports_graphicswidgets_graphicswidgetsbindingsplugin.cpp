$NetBSD$

Don't use kdewebkit

--- plasma/declarativeimports/graphicswidgets/graphicswidgetsbindingsplugin.cpp.orig	2017-10-01 01:02:55.000000000 +0000
+++ plasma/declarativeimports/graphicswidgets/graphicswidgetsbindingsplugin.cpp
@@ -47,7 +47,6 @@
 #include <Plasma/ToolButton>
 #include <Plasma/TreeView>
 #include <Plasma/VideoWidget>
-#include <Plasma/WebView>
 
 #include "declarativetabbar.h"
 
@@ -99,7 +98,6 @@ void GraphicsWidgetsBindingsPlugin::regi
     qmlRegisterType<Plasma::ToolButton>(uri, 0, 1, "ToolButton");
     qmlRegisterType<Plasma::TreeView>(uri, 0, 1, "TreeView");
     qmlRegisterType<Plasma::VideoWidget>(uri, 0, 1, "VideoWidget");
-    qmlRegisterType<Plasma::WebView>(uri, 0, 1, "WebView");
 }
 
 

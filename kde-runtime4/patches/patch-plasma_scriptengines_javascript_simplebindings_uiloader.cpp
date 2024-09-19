$NetBSD$

Don't use kdewebkit

--- plasma/scriptengines/javascript/simplebindings/uiloader.cpp.orig	2017-10-01 01:02:55.000000000 +0000
+++ plasma/scriptengines/javascript/simplebindings/uiloader.cpp
@@ -49,7 +49,6 @@
 #include <Plasma/TextEdit>
 #include <Plasma/ToolButton>
 #include <Plasma/TreeView>
-#include <Plasma/WebView>
 #include <Plasma/VideoWidget>
 
 
@@ -78,7 +77,6 @@ QGraphicsWidget *createTextEdit(QGraphic
 QGraphicsWidget *createToolButton(QGraphicsWidget *parent) { return new Plasma::ToolButton(parent); }
 QGraphicsWidget *createTreeView(QGraphicsWidget *parent) { return new Plasma::TreeView(parent); }
 QGraphicsWidget *createVideoWidget(QGraphicsWidget *parent) { return new Plasma::VideoWidget(parent); }
-QGraphicsWidget *createWebView(QGraphicsWidget *parent) { return new Plasma::WebView(parent); }
 QGraphicsWidget *createGraphicsWidget(QGraphicsWidget *parent) { return new QGraphicsWidget(parent); }
 
 UiLoader::UiLoader()
@@ -108,8 +106,6 @@ UiLoader::UiLoader()
     m_widgetCtors.insert("ToolButton", createToolButton);
     m_widgetCtors.insert("TreeView", createTreeView);
     m_widgetCtors.insert("VideoWidget", createVideoWidget);
-    m_widgetCtors.insert("WebView", createWebView);
-    m_widgetCtors.insert("GraphicsWidget", createWebView);
 }
 
 UiLoader::~UiLoader()

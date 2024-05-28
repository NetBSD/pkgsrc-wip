$NetBSD$

Switch-off the use layer-shell-qt for Desktop under Wayland.

--- pcmanfm/desktopwindow.cpp.orig	2024-05-28 11:17:06.695422960 +0000
+++ pcmanfm/desktopwindow.cpp
@@ -43,9 +43,6 @@
 #include <QRandomGenerator>
 #include <QToolTip>
 
-#include <LayerShellQt/shell.h>
-#include <LayerShellQt/window.h>
-
 #include "./application.h"
 #include "mainwindow.h"
 #include <libfm-qt6/foldermenu.h>
@@ -190,23 +187,6 @@ DesktopWindow::DesktopWindow(int screenN
     shortcut = new QShortcut(QKeySequence(Qt::SHIFT | Qt::Key_Delete), this); // force delete
     connect(shortcut, &QShortcut::activated, this, &DesktopWindow::onDeleteActivated);
 
-    // set the layer and anchors under Wayland
-    if(static_cast<Application*>(qApp)->underWayland()) {
-        winId();
-        if(QWindow* win = windowHandle()) {
-            if(LayerShellQt::Window* layershell = LayerShellQt::Window::get(win)) {
-                layershell->setLayer(LayerShellQt::Window::Layer::LayerBackground);
-                LayerShellQt::Window::Anchors anchors = {LayerShellQt::Window::AnchorTop
-                                                         | LayerShellQt::Window::AnchorBottom
-                                                         | LayerShellQt::Window::AnchorLeft
-                                                         | LayerShellQt::Window::AnchorRight};
-                layershell->setAnchors(anchors);
-                layershell->setKeyboardInteractivity(LayerShellQt::Window::KeyboardInteractivityOnDemand);
-                layershell->setExclusiveZone(-1); // not moved to accommodate for other surfaces
-                layershell->setScope(QStringLiteral("desktop")); // just for distinguishing it
-            }
-        }
-    }
 }
 
 DesktopWindow::~DesktopWindow() {

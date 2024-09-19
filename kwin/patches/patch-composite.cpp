$NetBSD$

Don't destroy DecorationRenderer in setup/finish compositing
commit 9a68cbd9b110b529021c128ea6650ce6774f462a

--- composite.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ composite.cpp
@@ -199,6 +199,8 @@ void Compositor::slotCompositingOptionsI
         }
     }
 
+    emit aboutToToggleCompositing();
+
     auto supportedCompositors = kwinApp()->platform()->supportedCompositors();
     const auto userConfigIt = std::find(supportedCompositors.begin(), supportedCompositors.end(), options->compositingMode());
     if (userConfigIt != supportedCompositors.end()) {
@@ -370,6 +372,9 @@ void Compositor::finish()
         return;
     m_finishing = true;
     m_releaseSelectionTimer.start();
+
+    emit aboutToToggleCompositing();
+
     if (Workspace::self()) {
         foreach (Client * c, Workspace::self()->clientList())
             m_scene->windowClosed(c, NULL);
@@ -1185,9 +1190,6 @@ bool Client::setupCompositing()
     if (!Toplevel::setupCompositing()){
         return false;
     }
-    if (isDecorated()) {
-        decoratedClient()->destroyRenderer();
-    }
     updateVisibility(); // for internalKeep()
     return true;
 }
@@ -1196,11 +1198,6 @@ void Client::finishCompositing(ReleaseRe
 {
     Toplevel::finishCompositing(releaseReason);
     updateVisibility();
-    if (!deleting) {
-        if (isDecorated()) {
-            decoratedClient()->destroyRenderer();
-        }
-    }
     // for safety in case KWin is just resizing the window
     resetHaveResizeEffect();
 }

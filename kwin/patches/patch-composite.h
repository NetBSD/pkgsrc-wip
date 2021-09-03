$NetBSD$

Don't destroy DecorationRenderer in setup/finish compositing
commit 9a68cbd9b110b529021c128ea6650ce6774f462a

--- composite.h.orig	2018-05-01 12:52:19.000000000 +0000
+++ composite.h
@@ -176,6 +176,7 @@ public Q_SLOTS:
 Q_SIGNALS:
     void compositingToggled(bool active);
     void aboutToDestroy();
+    void aboutToToggleCompositing();
     void sceneCreated();
 
 protected:

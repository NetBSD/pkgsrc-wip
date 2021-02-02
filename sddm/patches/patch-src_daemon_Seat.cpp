$NetBSD$

Patches from Fabian Vogt to retry starting the display server

--- src/daemon/Seat.cpp.orig	2020-11-02 10:03:22.000000000 +0000
+++ src/daemon/Seat.cpp
@@ -28,6 +28,7 @@
 
 #include <QDebug>
 #include <QFile>
+#include <QTimer>
 
 #include <functional>
 
@@ -52,7 +53,7 @@ namespace SDDM {
         return m_name;
     }
 
-    bool Seat::createDisplay(int terminalId) {
+    void Seat::createDisplay(int terminalId) {
         //reload config if needed
         mainConfig.load();
 
@@ -84,12 +85,24 @@ namespace SDDM {
         m_displays << display;
 
         // start the display
-        if (!display->start()) {
-            qCritical() << "Could not start Display server on vt" << terminalId;
-            return false;
+        startDisplay(display);
+    }
+
+    void Seat::startDisplay(Display *display, int tryNr) {
+        if (display->start())
+            return;
+
+        // It's possible that the system isn't ready yet (driver not loaded,
+        // device not enumerated, ...). It's not possible to tell when that changes,
+        // so try a few times with a delay in between.
+        qWarning() << "Attempt" << tryNr << "starting the Display server on vt" << display->terminalId() << "failed";
+
+        if(tryNr >= 3) {
+            qCritical() << "Could not start Display server on vt" << display->terminalId();
+            return;
         }
 
-        return true;
+        QTimer::singleShot(2000, display, [=] { startDisplay(display, tryNr + 1); });
     }
 
     void Seat::removeDisplay(Display* display) {

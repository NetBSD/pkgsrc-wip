$NetBSD$

Patches from Fabian Vogt to retry starting the display server

--- src/daemon/Seat.h.orig	2020-11-02 10:03:22.000000000 +0000
+++ src/daemon/Seat.h
@@ -35,13 +35,15 @@ namespace SDDM {
         const QString &name() const;
 
     public slots:
-        bool createDisplay(int terminalId = -1);
+        void createDisplay(int terminalId = -1);
         void removeDisplay(SDDM::Display* display);
 
     private slots:
         void displayStopped();
 
     private:
+        void startDisplay(SDDM::Display *display, int tryNr = 1);
+
         QString m_name;
 
         QVector<Display *> m_displays;

$NetBSD$

# Upstream bug
--- src/FreqTable.h.orig	2017-02-22 08:30:03 UTC
+++ src/FreqTable.h
@@ -15,7 +15,7 @@ public:
     };
     void remove(const T& t) {
         if (this->data.find(t) == this->data.end()) {
-            return false;
+            return;
         }
         this->data[t] -- ;
         this->isSorted = false;

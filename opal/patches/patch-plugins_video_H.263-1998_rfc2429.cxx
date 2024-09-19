$NetBSD$

--- plugins/video/H.263-1998/rfc2429.cxx.orig	2013-02-20 02:18:03.000000000 +0000
+++ plugins/video/H.263-1998/rfc2429.cxx
@@ -418,7 +418,7 @@ size_t RFC2429Frame::parseHeader(uint8_t
   bool PB  = false;
   bool CPM = false;
   //bool PEI = false;
-  bool SS  = false;
+  bool SS_  = false;
   bool RPS = false;
   bool PCF = false;
   bool UMV = false;
@@ -444,9 +444,9 @@ size_t RFC2429Frame::parseHeader(uint8_t
                              << " AP: "  << headerBits.GetBits(1) 
                              << " AIC: " << headerBits.GetBits(1)
                              << " DF: "  << headerBits.GetBits(1));
-      SS = headerBits.GetBits(1);
+      SS_ = headerBits.GetBits(1);
       RPS = headerBits.GetBits(1);
-      PTRACE(6, "H.263-RFC2429", "Header\tSS: "  << SS
+      PTRACE(6, "H.263-RFC2429", "Header\tSS: "  << SS_
                           << " RPS: " << RPS
                           << " ISD: " << headerBits.GetBits(1)
                           << " AIV: " << headerBits.GetBits(1)
@@ -501,7 +501,7 @@ size_t RFC2429Frame::parseHeader(uint8_t
           else
            PTRACE(6, "H.263-RFC2429", "Header\tUUI: 0" << headerBits.GetBits(1));
       }
-      if (SS) {
+      if (SS_) {
         PTRACE(6, "H.263-RFC2429", "Header\tSSS:" << headerBits.GetBits(2));
       }
     }

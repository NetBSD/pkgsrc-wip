$NetBSD$

--- src/astream.cc.orig	2008-01-30 17:02:57.000000000 +0000
+++ src/astream.cc
@@ -44,6 +44,7 @@ oastream::oastream()
     m_format.channels = 2;
     m_format.rate = 44100;
     m_format.byte_format = AO_FMT_LITTLE;
+    m_format.matrix=NULL;
 
     ao_initialize();
 }

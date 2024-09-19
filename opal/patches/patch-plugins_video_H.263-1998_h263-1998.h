$NetBSD$

--- plugins/video/H.263-1998/h263-1998.h.orig	2013-02-20 02:18:03.000000000 +0000
+++ plugins/video/H.263-1998/h263-1998.h
@@ -115,7 +115,7 @@ class H263_Base_EncoderContext
     virtual ~H263_Base_EncoderContext();
 
     virtual bool Init() = 0;
-    virtual bool Init(CodecID codecId);
+    virtual bool Init(AVCodecID codecId);
 
     virtual bool SetOptions(const char * const * options);
     virtual void SetOption(const char * option, const char * value);

$NetBSD: patch-remoting_base_compound__buffer.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- remoting/base/compound_buffer.h.orig	2011-04-13 08:01:07.000000000 +0000
+++ remoting/base/compound_buffer.h
@@ -111,7 +111,7 @@ class CompoundBufferInputStream
   virtual bool Next(const void** data, int* size);
   virtual void BackUp(int count);
   virtual bool Skip(int count);
-  virtual int64 ByteCount() const;
+  virtual int64_t ByteCount() const;
 
  private:
   const CompoundBuffer* buffer_;

$NetBSD$

--- src/vm/encee.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/encee.cpp
@@ -654,7 +654,7 @@ HRESULT EditAndContinueModule::ResumeInU
     if( newFrameSize > oldFrameSize) 
     {
         DWORD frameIncrement = newFrameSize - oldFrameSize;
-        (void)alloca(frameIncrement);
+        (void)Alloca(frameIncrement);
     }
 
     // Ask the EECodeManager to actually fill in the context and stack for the new frame so that

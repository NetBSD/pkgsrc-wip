$NetBSD$

--- src/zap/zapcode.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/zap/zapcode.cpp
@@ -1902,7 +1902,7 @@ void ZapHelperThunk::Save(ZapWriter * pZ
     DWORD pad = GetSize() - sizeof(DWORD);
     if (pad > 0)
     {
-        void * pPad = _alloca(pad);
+        void * pPad = Alloca(pad);
         memset(pPad, DEFAULT_CODE_BUFFER_INIT, pad);
         pZapWriter->Write(pPad, pad);
     }

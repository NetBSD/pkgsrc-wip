$NetBSD$

--- src/md/enc/stgio.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/md/enc/stgio.cpp
@@ -1305,7 +1305,7 @@ HRESULT StgIO::CopyFileInternal(        
     DWORD       cbRead;                 // Byte count for buffer.
     DWORD       cbWrite;                // Check write of bytes.
     const DWORD cbBuff = 4096;          // Size of buffer for copy (in bytes).
-    BYTE       *pBuff = (BYTE*)alloca(cbBuff); // Buffer for copy.
+    BYTE       *pBuff = (BYTE*)Alloca(cbBuff); // Buffer for copy.
     HANDLE      hFile;                  // Target file.
     HRESULT     hr = S_OK;
 

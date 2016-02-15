$NetBSD$

--- src/debug/ildbsymlib/symread.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/ildbsymlib/symread.cpp
@@ -241,7 +241,7 @@ HRESULT SymReader::InitializeFromStream(
     // Make sure we're at the beginning of the stream
     IfFailGo(pIStream->Seek(li, STREAM_SEEK_SET, NULL));
 
-    IfNullGo(pSignature = (BYTE *)_alloca(ILDB_SIGNATURE_SIZE));
+    IfNullGo(pSignature = (BYTE *)Alloca(ILDB_SIGNATURE_SIZE));
     IfFailGo(ReadFromStream(pIStream, pSignature, ILDB_SIGNATURE_SIZE));
     
     // Verify that we're looking at an ILDB File

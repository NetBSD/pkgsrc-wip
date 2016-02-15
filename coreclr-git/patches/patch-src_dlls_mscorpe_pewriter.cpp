$NetBSD$

--- src/dlls/mscorpe/pewriter.cpp.orig	2016-02-02 22:59:18.000000000 +0000
+++ src/dlls/mscorpe/pewriter.cpp
@@ -1572,7 +1572,7 @@ HRESULT PEWriter::link() {
     // First collect all information into entries[]
 
     int sectCount = getSectCount();
-    entry *entries = (entry *) _alloca(sizeof(entry) * sectCount);
+    entry *entries = (entry *) Alloca(sizeof(entry) * sectCount);
 
     unsigned iUniqueSections, iEntries;
     HRESULT hr;
@@ -2279,7 +2279,7 @@ HRESULT PEWriter::write(void ** ppImage)
 {
     bool ExeOrDll = isExeOrDll(m_ntHeaders);
     const unsigned RoundUpVal = VAL32(m_ntHeaders->OptionalHeader.FileAlignment);
-    char *pad = (char *) _alloca(RoundUpVal);
+    char *pad = (char *) Alloca(RoundUpVal);
     memset(pad, 0, RoundUpVal);
 
     size_t lSize = filePos;

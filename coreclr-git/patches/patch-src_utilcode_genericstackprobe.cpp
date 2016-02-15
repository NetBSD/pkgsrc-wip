$NetBSD$

--- src/utilcode/genericstackprobe.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/utilcode/genericstackprobe.cpp
@@ -316,7 +316,7 @@ void BaseStackMarker::SetMarker(float nu
     
     // We might not have committed our stack yet, so allocate the number of pages
     // we need so that they will be commited and we won't AV when we try to set the mark.
-    _alloca( (int)(OS_PAGE_SIZE * m_numPages) );
+    Alloca( (int)(OS_PAGE_SIZE * m_numPages) );
     m_pMarker = pMarker;
     *m_pMarker = STACK_COOKIE_VALUE;
 

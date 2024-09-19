$NetBSD$

--- src/VBox/Additions/common/VBoxGuestLib/VBoxGuestR3LibLog.cpp.orig	2016-03-04 19:23:10.000000000 +0000
+++ src/VBox/Additions/common/VBoxGuestLib/VBoxGuestR3LibLog.cpp
@@ -66,7 +66,7 @@ VBGLR3DECL(int) VbglR3WriteLog(const cha
     RTMemFree(pvTmp);
     return rc;
 
-#elif 0 /** @todo Several OSes could take this route (solaris and freebsd for instance). */
+#elif 0 /** @todo Several OSes could take this route (solaris, freebsd and netbsd for instance). */
     /*
      * Handle the entire request in one go.
      */
@@ -88,4 +88,3 @@ VBGLR3DECL(int) VbglR3WriteLog(const cha
     return rc;
 #endif
 }
-

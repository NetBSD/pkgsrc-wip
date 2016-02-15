$NetBSD$

--- src/inc/allocacheck.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/inc/allocacheck.h
@@ -72,12 +72,12 @@ private:
 };
 
 #define ALLOCA_CHECK() AllocaCheck __allocaChecker
-#define ALLOCA(size)  __allocaChecker.add(_alloca(size+sizeof(AllocaCheck::AllocaSentinal)), size);
+#define ALLOCA(size)  __allocaChecker.add(Alloca(size+sizeof(AllocaCheck::AllocaSentinal)), size);
 
 #else
 
 #define ALLOCA_CHECK() 
-#define ALLOCA(size)  _alloca(size)
+#define ALLOCA(size)  Alloca(size)
 
 #endif
 	

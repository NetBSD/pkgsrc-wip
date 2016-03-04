$NetBSD$

Cannot pass non-trivial type TString through variadic method Format.

--- modules/fxpackager/src/main/native/library/common/PlatformString.h.orig	2016-03-04 00:57:09.000000000 +0000
+++ modules/fxpackager/src/main/native/library/common/PlatformString.h
@@ -188,7 +188,7 @@ public:
     PlatformString(JNIEnv *env, jstring value);
     PlatformString(size_t Value);
 
-    static TString Format(const TString value, ...);
+    static TString Format(const char* value, ...);
 
     ~PlatformString(void);
 

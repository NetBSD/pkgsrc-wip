$NetBSD$

Cannot pass non-trivial type TString through variadic method Format.

--- modules/fxpackager/src/main/native/library/common/PlatformString.cpp.orig	2016-03-04 00:57:09.000000000 +0000
+++ modules/fxpackager/src/main/native/library/common/PlatformString.cpp
@@ -268,7 +268,7 @@ PlatformString::PlatformString(JNIEnv *e
     }
 }
 
-TString PlatformString::Format(const TString value, ...) {
+TString PlatformString::Format(const char* value, ...) {
 //std::string PlatformString::Format(std::string value, ...) {
     TString result = value;
 

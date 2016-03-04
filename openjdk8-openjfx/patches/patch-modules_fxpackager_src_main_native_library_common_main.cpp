$NetBSD$

Cannot pass non-trivial type TString through variadic method Format.

--- modules/fxpackager/src/main/native/library/common/main.cpp.orig	2016-03-04 00:57:09.000000000 +0000
+++ modules/fxpackager/src/main/native/library/common/main.cpp
@@ -182,7 +182,7 @@ extern "C" {
 
                             if (FilePath::FileExists(cacheFileName) == false) {
                                 Messages& messages = Messages::GetInstance();
-                                TString message = PlatformString::Format(messages.GetMessage(APPCDS_CACHE_FILE_NOT_FOUND), cacheFileName.data());
+                                TString message = PlatformString::Format(messages.GetMessage(APPCDS_CACHE_FILE_NOT_FOUND).c_str(), cacheFileName.data());
                                 throw FileNotFoundException(message);
                             }
                             break;

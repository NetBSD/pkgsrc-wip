$NetBSD$

Cannot pass non-trivial type TString through variadic method Format.

--- modules/fxpackager/src/main/native/library/common/Java.cpp.orig	2016-03-04 00:57:09.000000000 +0000
+++ modules/fxpackager/src/main/native/library/common/Java.cpp
@@ -225,7 +225,7 @@ JavaClass::JavaClass(JNIEnv *Env, TStrin
     if (FClass == NULL || FEnv->ExceptionCheck() == JNI_TRUE) {
         Messages& messages = Messages::GetInstance();
         TString message = messages.GetMessage(CLASS_NOT_FOUND);
-        message = PlatformString::Format(message, FClassName.data());
+        message = PlatformString::Format(message.c_str(), FClassName.data());
         throw JavaException(FEnv, message);
     }
 }
@@ -244,7 +244,7 @@ JavaStaticMethod JavaClass::GetStaticMet
     if (method == NULL || FEnv->ExceptionCheck() == JNI_TRUE) {
         Messages& messages = Messages::GetInstance();
         TString message = messages.GetMessage(METHOD_NOT_FOUND);
-        message = PlatformString::Format(message, Name.data(), FClassName.data());
+        message = PlatformString::Format(message.c_str(), Name.data(), FClassName.data());
         throw JavaException(FEnv, message);
     }
 
@@ -263,7 +263,7 @@ void JavaStringArray::Initialize(size_t 
     if (FEnv->ExceptionCheck() == JNI_TRUE) {
         Messages& messages = Messages::GetInstance();
         TString message = messages.GetMessage(CLASS_NOT_FOUND);
-        message = PlatformString::Format(message, _T("String"));
+        message = PlatformString::Format(message.c_str(), _T("String"));
         throw JavaException(FEnv, message.data());
     }
 

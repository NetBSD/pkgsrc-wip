$NetBSD: patch-Source_JavaScriptCore_API_ObjCCallbackFunction.h,v 1.1 2015/02/23 16:11:06 leot1990 Exp $

--- src/qt/qtwebkit/Source/JavaScriptCore/API/ObjCCallbackFunction.h.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/JavaScriptCore/API/ObjCCallbackFunction.h
@@ -29,7 +29,7 @@
 
 #if JSC_OBJC_API_ENABLED
 
-#import <JavaScriptCore/JSCallbackFunction.h>
+#import <JavaScriptCore/API/JSCallbackFunction.h>
 
 #if defined(__OBJC__)
 JSObjectRef objCCallbackFunctionForMethod(JSContext *, Class, Protocol *, BOOL isInstanceMethod, SEL, const char* types);

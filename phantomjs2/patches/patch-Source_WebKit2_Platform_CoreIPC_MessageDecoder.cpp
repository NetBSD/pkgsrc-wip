$NetBSD: patch-Source_WebKit2_Platform_CoreIPC_MessageDecoder.cpp,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

--- src/qt/qtwebkit/Source/WebKit2/Platform/CoreIPC/MessageDecoder.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WebKit2/Platform/CoreIPC/MessageDecoder.cpp
@@ -31,7 +31,7 @@
 #include "MessageFlags.h"
 #include "StringReference.h"
 
-#if PLATFORM(MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
+#if defined(Q_OS_MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
 #include "ImportanceAssertion.h"
 #endif
 
@@ -77,7 +77,7 @@ bool MessageDecoder::shouldDispatchMessa
     return m_messageFlags & DispatchMessageWhenWaitingForSyncReply;
 }
 
-#if PLATFORM(MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
+#if defined(Q_OS_MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
 void MessageDecoder::setImportanceAssertion(PassOwnPtr<ImportanceAssertion> assertion)
 {
     m_importanceAssertion = assertion;

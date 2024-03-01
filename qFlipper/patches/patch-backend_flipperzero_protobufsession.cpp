$NetBSD$

Add NetBSD loader support.

--- backend/flipperzero/protobufsession.cpp.orig	2023-11-10 09:40:31.000000000 +0000
+++ backend/flipperzero/protobufsession.cpp
@@ -445,7 +445,7 @@ const QString ProtobufSession::protobufP
     return QStringLiteral("flipperproto%1.dll").arg(versionMajor);
 #elif defined(Q_OS_MAC)
     return QStringLiteral("libflipperproto%1.dylib").arg(versionMajor);
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_NETBSD)
     return QStringLiteral("libflipperproto%1.so").arg(versionMajor);
 #else
 #error "Unsupported OS"

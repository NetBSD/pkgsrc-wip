$NetBSD$

* https://bugreports.qt.io/browse/QTBUG-106980
  fixes build on SunOS, fixed in 6.4.1

--- src/corelib/global/qlogging.cpp.orig	2022-09-19 10:23:04.000000000 +0000
+++ src/corelib/global/qlogging.cpp
@@ -1302,7 +1302,7 @@ static QStringList backtraceFramesForLog
     // use dladdr() instead of backtrace_symbols()
     QString cachedLibrary;
     const char *cachedFname = nullptr;
-    auto decodeFrame = [&](const void *addr) -> DecodedFrame {
+    auto decodeFrame = [&](void *addr) -> DecodedFrame {
         Dl_info info;
         if (!dladdr(addr, &info))
             return {};

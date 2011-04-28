$NetBSD: patch-third__party_WebKit_Source_WebCore_platform_sql_chromium_SQLiteFileSystemChromiumPosix.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/platform/sql/chromium/SQLiteFileSystemChromiumPosix.cpp.orig	2011-04-13 08:12:24.000000000 +0000
+++ third_party/WebKit/Source/WebCore/platform/sql/chromium/SQLiteFileSystemChromiumPosix.cpp
@@ -755,6 +755,8 @@ static bool syncWrapper(int fd, bool ful
     if (!success)
         success = !fsync(fd);
     return success;
+#elif OS(OPENBSD)
+    return !fsync(fd);
 #else
     return !fdatasync(fd);
 #endif

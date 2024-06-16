$NetBSD$

Treat NetBSD like linux.

--- src/libslic3r/Utils/DirectoriesUtils.cpp.orig	2024-06-15 08:21:25.981869460 +0000
+++ src/libslic3r/Utils/DirectoriesUtils.cpp
@@ -46,7 +46,7 @@ static std::string GetDataDir()
     return  boost::nowide::narrow(buffer);
 }
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__NetBSD__)
 
 #include <stdlib.h>
 #include <pwd.h>

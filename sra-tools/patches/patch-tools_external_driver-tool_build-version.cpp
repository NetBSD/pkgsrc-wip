$NetBSD$

# Resolve collision on NetBSD

--- tools/external/driver-tool/build-version.cpp.orig	2023-08-13 20:53:11.943803445 +0000
+++ tools/external/driver-tool/build-version.cpp
@@ -60,7 +60,7 @@ public:
     }
 
     VersionBuffer(sratools::Version const &vers) noexcept {
-        begin = utoa(vers.major(), '.', utoa(vers.minor(), '.', utoa(vers.revision(), '\0', end())));
+        begin = utoa(vers.ncbi_major(), '.', utoa(vers.ncbi_minor(), '.', utoa(vers.revision(), '\0', end())));
     }
 };
 

$NetBSD$

# Resolve collision on NetBSD

--- tools/external/driver-tool/build-version.hpp.orig	2023-08-13 20:51:13.494470918 +0000
+++ tools/external/driver-tool/build-version.hpp
@@ -77,12 +77,12 @@ struct Version {
     : packed((((uint32_t)major) << 24) | (((uint32_t)minor) << 16) | ((uint32_t)revision))
     {}
 
-    unsigned major() const noexcept { return packed >> 24; }
-    unsigned minor() const noexcept { return (packed >> 16) & 0xFF; }
+    unsigned ncbi_major() const noexcept { return packed >> 24; }
+    unsigned ncbi_minor() const noexcept { return (packed >> 16) & 0xFF; }
     unsigned revision() const noexcept { return packed & 0xFFFF; }
 
-    Version nextMinor() const noexcept { return Version(uint8_t(major()), uint8_t(minor() + 1), 0); }
-    Version nextMajor() const noexcept { return Version(uint8_t(major() + 1), 0, 0); }
+    Version nextMinor() const noexcept { return Version(uint8_t(ncbi_major()), uint8_t(ncbi_minor() + 1), 0); }
+    Version nextMajor() const noexcept { return Version(uint8_t(ncbi_major() + 1), 0, 0); }
 
     /// \brief Scan the name for a version string; if found, remove it.
     /// \Returns The found version or `Version()`.

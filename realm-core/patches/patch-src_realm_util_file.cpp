$NetBSD$

--- src/realm/util/file.cpp.orig	2020-06-30 08:11:11.000000000 +0000
+++ src/realm/util/file.cpp
@@ -820,6 +820,16 @@ void File::prealloc(size_t size)
 
     consume_space_interlocked();
 
+#elif REALM_NETBSD
+    int ret = 0;
+
+    do {
+        ret = ftruncate(m_fd, new_size);
+    } while (ret == -1 && errno == EINTR);
+
+    if (ret != 0) {
+        throw std::system_error(errno, std::system_category(), "ftruncate() inside prealloc() failed");
+    }
 #else
 #error Please check if/how your OS supports file preallocation
 #endif
@@ -1536,7 +1546,7 @@ DirScanner::~DirScanner() noexcept
 
 bool DirScanner::next(std::string& name)
 {
-#if !defined(__linux__) && !REALM_PLATFORM_APPLE && !REALM_WINDOWS && !REALM_UWP && !REALM_ANDROID
+#if !defined(__linux__) && !REALM_PLATFORM_APPLE && !REALM_WINDOWS && !REALM_UWP && !REALM_ANDROID && !REALM_NETBSD
 #error "readdir() is not known to be thread-safe on this platform"
 #endif
 

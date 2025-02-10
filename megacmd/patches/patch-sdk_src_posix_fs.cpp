$NetBSD: patch-sdk_src_posix_fs.cpp,v 1.2 2024/06/18 18:23:15 bsiegert Exp $

* Fix build on NetBSD, use statvfs
* Don't use mntent features on BSDs
* O_NOATIME not available on BSDs

--- sdk/src/posix/fs.cpp.orig	2025-01-24 13:56:57.000000000 +0100
+++ sdk/src/posix/fs.cpp
@@ -22,7 +22,8 @@
  * You should have received a copy of the license along with this
  * program.
  */
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && \
+    !defined(__NetBSD__) && !defined(__DragonFly__)
 #include <mntent.h>
 #endif // ! __APPLE__
 
@@ -32,6 +33,9 @@
 #include <sys/ioctl.h>
 #include <sys/resource.h>
 #include <sys/statvfs.h>
+#if defined(__NetBSD__)
+#define statfs statvfs
+#endif
 #include <sys/types.h>
 #include <sys/utsname.h>
 #ifdef TARGET_OS_MAC
@@ -876,6 +880,24 @@ bool PosixFileSystemAccess::cwd_static(L
     return true;
 }
 
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+
+BSDFileSystemAccess::~BSDFileSystemAccess()
+{
+   // do nothing, as no notifiers
+}
+
+void BSDFileSystemAccess::addevents([[maybe_unused]] Waiter* waiter, int /*flags*/)
+{
+   // do nothing
+}
+
+int BSDFileSystemAccess::checkevents(Waiter*)
+{
+    return 0;
+}
+
+#endif
 // wake up from filesystem updates
 
 #ifdef __linux__
@@ -1802,8 +1824,8 @@ private:
     // open with O_NOATIME if possible
     int open(const char *path)
     {
-#ifdef TARGET_OS_IPHONE
-        // building for iOS, there is no O_NOATIME flag
+#ifndef O_NOATIME
+        // building for iOS and BSDs, there is no O_NOATIME flag
         int fd = ::open(path, O_RDONLY) ;
 #else
         // for sync in particular, try to open without setting access-time
@@ -2062,6 +2084,7 @@ ScanResult PosixFileSystemAccess::direct
 }
 
 #ifndef __APPLE__
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 
 // Determine which device contains the specified path.
 static std::string deviceOf(const std::string& database,
@@ -2230,6 +2253,7 @@ static std::string deviceOf(const std::s
     // No database has a mapping for this path.
     return std::string();
 }
+#endif
 
 // Compute legacy filesystem fingerprint.
 static std::uint64_t fingerprintOf(const std::string& path)
@@ -2258,6 +2282,7 @@ static std::uint64_t fingerprintOf(const
     return ++value;
 }
 
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 // Determine the UUID of the specified device.
 static std::string uuidOf(const std::string& device)
 {
@@ -2334,6 +2359,7 @@ static std::string uuidOf(const std::str
     // Couldn't determine device's UUID.
     return std::string();
 }
+#endif
 
 fsfp_t FileSystemAccess::fsFingerprint(const LocalPath& path) const
 {
@@ -2344,6 +2370,7 @@ fsfp_t FileSystemAccess::fsFingerprint(c
     if (!fingerprint)
         return fsfp_t();
 
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
     // What device contains the specified path?
     auto device = deviceOf(path.localpath);
 
@@ -2360,6 +2387,7 @@ fsfp_t FileSystemAccess::fsFingerprint(c
 
     LOG_warn << "Falling back to legacy filesystem fingerprint: "
              << path;
+#endif
 
     // Couldn't determine filesystem UUID.
     return fsfp_t(fingerprint, std::string());

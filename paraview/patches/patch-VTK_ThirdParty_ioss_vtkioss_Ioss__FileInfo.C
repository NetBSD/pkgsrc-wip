$NetBSD$

NFS temporarily disabled for NetBSD

--- VTK/ThirdParty/ioss/vtkioss/Ioss_FileInfo.C.orig	2022-11-14 01:46:47.000000000 +0000
+++ VTK/ThirdParty/ioss/vtkioss/Ioss_FileInfo.C
@@ -30,6 +30,7 @@
 #if defined(__APPLE__) && defined(__MACH__)
 #include <sys/param.h>
 #include <sys/mount.h>
+#elif defined(__NetBSD__)
 #else
 #include <sys/statfs.h>
 #endif
@@ -171,7 +172,7 @@ namespace Ioss {
   //: Return TRUE if file is on an NFS filesystem...
   bool FileInfo::is_nfs() const
   {
-#if !defined(__IOSS_WINDOWS__)
+#if !defined(__IOSS_WINDOWS__) && !defined(__NetBSD__)
 #define NFS_FS	0x6969  /* statfs defines that 0x6969 is NFS filesystem */
     auto tmp_path = pathname();
     if (tmp_path.empty()) {

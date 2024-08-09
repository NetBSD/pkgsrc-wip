$NetBSD$

NFS temporarily disabled for NetBSD

--- VTK/ThirdParty/ioss/vtkioss/Ioss_FileInfo.C.orig	2024-05-17 19:18:15.000000000 +0000
+++ VTK/ThirdParty/ioss/vtkioss/Ioss_FileInfo.C
@@ -174,7 +174,7 @@ namespace Ioss {
   //: Return TRUE if file is on an NFS filesystem...
   bool FileInfo::is_nfs() const
   {
-#if !defined(__IOSS_WINDOWS__)
+#if !defined(__IOSS_WINDOWS__) && !defined(__NetBSD__)
 #define NFS_FS	0x6969  /* statfs defines that 0x6969 is NFS filesystem */
     auto tmp_path = pathname();
     if (tmp_path.empty()) {

$NetBSD$

NFS temporarily disabled for NetBSD

--- VTK/ThirdParty/ioss/vtkioss/Ioss_FileInfo.C.orig	2024-09-27 01:54:08.000000000 +0000
+++ VTK/ThirdParty/ioss/vtkioss/Ioss_FileInfo.C
@@ -172,7 +172,7 @@ namespace Ioss {
   //: Return TRUE if file is on an NFS filesystem...
   bool FileInfo::is_nfs() const
   {
-#if !defined(__IOSS_WINDOWS__)
+#if !defined(__IOSS_WINDOWS__) && !defined(__NetBSD__)
     auto tmp_path = pathname();
     if (tmp_path.empty()) {
       char *current_cwd = getcwd(nullptr, 0);

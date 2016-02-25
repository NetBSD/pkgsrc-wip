$NetBSD$

--- src/System.IO.FileSystem/src/System/IO/WinRTFileSystem.cs.orig	2016-01-30 00:20:59.000000000 +0000
+++ src/System.IO.FileSystem/src/System/IO/WinRTFileSystem.cs
@@ -563,7 +563,7 @@ namespace System.IO
                 throw Win32Marshal.GetExceptionForWin32Error(Interop.mincore.Errors.ERROR_DIR_NOT_EMPTY, fullPath);
 
             // StorageFolder.Delete ignores readonly attribute.  Detect and throw.
-            if ((folder.Attributes & Windows.Storage.FileAttributes.ReadOnly) == Windows.Storage.FileAttributes.ReadOnly)
+            if ((folder.Attributes & WinRTFileAttributes.ReadOnly) == WinRTFileAttributes.ReadOnly)
                 throw new IOException(SR.Format(SR.UnauthorizedAccess_IODenied_Path, fullPath));
 
             StorageFolder parentFolder = await folder.GetParentAsync().TranslateWinRTTask(fullPath, isDirectory: true);

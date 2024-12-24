$NetBSD$

* NetBSD has no statfs(2).

--- JuceLibraryCode/modules/juce_core/native/juce_Files_linux.cpp.orig	2024-12-24 09:10:52.169020955 +0000
+++ JuceLibraryCode/modules/juce_core/native/juce_Files_linux.cpp
@@ -31,6 +31,38 @@ enum
     U_SMB_SUPER_MAGIC = 0x517B      // linux/smb_fs.h
 };
 
+#if defined(__NetBSD__)
+bool File::isOnCDRomDrive() const
+{
+    struct statvfs buf;
+
+    return statvfs (getFullPathName().toUTF8(), &buf) == 0
+             && (strcmp(buf.f_fstypename, MOUNT_CD9660) == 0);
+}
+
+bool File::isOnHardDisk() const
+{
+    struct statvfs buf;
+
+    if (statvfs (getFullPathName().toUTF8(), &buf) == 0)
+    {
+        if ((strcmp(buf.f_fstypename, MOUNT_CD9660) == 0) ||
+            (strcmp(buf.f_fstypename, MOUNT_MSDOS) == 0) ||
+            (strcmp(buf.f_fstypename, MOUNT_NFS) == 0) ||
+            (strcmp(buf.f_fstypename, MOUNT_SMBFS) == 0))
+            return false;
+    }
+
+    // Assume so if this fails for some reason
+    return true;
+}
+
+bool File::isOnRemovableDrive() const
+{
+    jassertfalse; // xxx not implemented for NetBSD!
+    return false;
+}
+#else
 bool File::isOnCDRomDrive() const
 {
     struct statfs buf;
@@ -66,6 +98,7 @@ bool File::isOnRemovableDrive() const
     jassertfalse; // xxx not implemented for linux!
     return false;
 }
+#endif
 
 String File::getVersion() const
 {

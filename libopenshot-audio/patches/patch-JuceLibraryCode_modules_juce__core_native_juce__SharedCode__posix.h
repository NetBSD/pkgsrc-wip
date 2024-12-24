$NetBSD$

* NetBSD has no statfs(2).
* NetBSD's pthread_setname_np(3) has different fingerprint.

--- JuceLibraryCode/modules/juce_core/native/juce_SharedCode_posix.h.orig	2024-12-21 22:21:33.000000000 +0000
+++ JuceLibraryCode/modules/juce_core/native/juce_SharedCode_posix.h
@@ -181,6 +181,21 @@ namespace
     }
 
    #if ! JUCE_WASM
+     #if defined(__NetBSD__)
+    // if this file doesn't exist, find a parent of it that does..
+    bool juce_doStatFS (File f, struct statvfs& result)
+    {
+        for (int i = 5; --i >= 0;)
+        {
+            if (f.exists())
+                break;
+
+            f = f.getParentDirectory();
+        }
+
+        return statvfs (f.getFullPathName().toUTF8(), &result) == 0;
+    }
+      #else
     // if this file doesn't exist, find a parent of it that does..
     bool juce_doStatFS (File f, struct statfs& result)
     {
@@ -195,6 +210,8 @@ namespace
         return statfs (f.getFullPathName().toUTF8(), &result) == 0;
     }
 
+      #endif
+
    #if JUCE_MAC || JUCE_IOS
     static int64 getCreationTime (const juce_statStruct& s) noexcept     { return (int64) s.st_birthtime; }
    #else
@@ -628,6 +645,27 @@ File juce_getExecutableFile()
 }
 
 //==============================================================================
+#if defined(__NetBSD__)
+int64 File::getBytesFreeOnVolume() const
+{
+    struct statvfs buf;
+
+    if (juce_doStatFS (*this, buf))
+        return (int64) buf.f_bsize * (int64) buf.f_bavail; // Note: this returns space available to non-super user
+
+    return 0;
+}
+
+int64 File::getVolumeTotalSize() const
+{
+    struct statvfs buf;
+
+    if (juce_doStatFS (*this, buf))
+        return (int64) buf.f_bsize * (int64) buf.f_blocks;
+
+    return 0;
+}
+#else
 int64 File::getBytesFreeOnVolume() const
 {
     struct statfs buf;
@@ -647,6 +685,7 @@ int64 File::getVolumeTotalSize() const
 
     return 0;
 }
+#endif
 
 String File::getVolumeLabel() const
 {
@@ -992,7 +1031,11 @@ void JUCE_CALLTYPE Thread::setCurrentThr
     #if (JUCE_BSD \
           || (JUCE_LINUX && (__GLIBC__ * 1000 + __GLIBC_MINOR__) >= 2012) \
           || (JUCE_ANDROID && __ANDROID_API__ >= 9))
+     #if defined(__NetBSD__)
+     pthread_setname_np (pthread_self(), "%s", const_cast<char*>(name.toRawUTF8()));
+     #else
      pthread_setname_np (pthread_self(), name.toRawUTF8());
+     #endif
     #else
      prctl (PR_SET_NAME, name.toRawUTF8(), 0, 0, 0);
     #endif

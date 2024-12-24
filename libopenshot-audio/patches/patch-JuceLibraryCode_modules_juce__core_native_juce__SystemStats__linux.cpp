$NetBSD$

* For NetBSD's KERN_PROC_PID.

--- JuceLibraryCode/modules/juce_core/native/juce_SystemStats_linux.cpp.orig	2024-12-24 10:09:57.592672459 +0000
+++ JuceLibraryCode/modules/juce_core/native/juce_SystemStats_linux.cpp
@@ -406,6 +406,7 @@ bool Time::setSystemTimeToThisTime() con
 JUCE_API bool JUCE_CALLTYPE juce_isRunningUnderDebugger() noexcept
 {
    #if JUCE_BSD
+     #if !defined(__NetBSD__)
     int mib[] =
     {
         CTL_KERN,
@@ -417,6 +418,21 @@ JUCE_API bool JUCE_CALLTYPE juce_isRunni
     auto infoSize = sizeof (info);
     auto result = sysctl (mib, numElementsInArray (mib), &info, &infoSize, nullptr, 0);
     return result == 0 ? ((info.ki_flag & P_TRACED) != 0) : false;
+     #else
+    struct kinfo_proc2 info;
+    auto infoSize = sizeof (info);
+    int mib[] =
+    {
+        CTL_KERN,
+        KERN_PROC2,
+        KERN_PROC_PID,
+        ::getpid(),
+        infoSize,
+        1
+    };
+    auto result = sysctl (mib, numElementsInArray (mib), &info, &infoSize, nullptr, 0);
+    return result == 0 ? ((info.p_flag & P_TRACED) != 0) : false;
+     #endif
    #else
     return readPosixConfigFileValue ("/proc/self/status", "TracerPid").getIntValue() > 0;
    #endif

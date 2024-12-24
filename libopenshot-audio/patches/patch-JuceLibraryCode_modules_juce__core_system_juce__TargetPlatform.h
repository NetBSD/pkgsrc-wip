$NetBSD$

* Define JUCE_BSD for NetBSD.

--- JuceLibraryCode/modules/juce_core/system/juce_TargetPlatform.h.orig	2024-12-24 08:56:33.703819564 +0000
+++ JuceLibraryCode/modules/juce_core/system/juce_TargetPlatform.h
@@ -62,7 +62,7 @@
 #elif defined (JUCE_ANDROID)
   #undef        JUCE_ANDROID
   #define       JUCE_ANDROID 1
-#elif defined (__FreeBSD__) || defined (__OpenBSD__)
+#elif defined (__FreeBSD__) || defined (__OpenBSD__) || defined(__NetBSD__)
   #define       JUCE_BSD 1
 #elif defined (LINUX) || defined (__linux__)
   #define       JUCE_LINUX 1

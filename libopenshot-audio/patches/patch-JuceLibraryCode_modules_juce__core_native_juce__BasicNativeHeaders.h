$NetBSD$

* NetBSD has no sys/user.h.

--- JuceLibraryCode/modules/juce_core/native/juce_BasicNativeHeaders.h.orig	2024-12-24 08:57:48.176841166 +0000
+++ JuceLibraryCode/modules/juce_core/native/juce_BasicNativeHeaders.h
@@ -243,7 +243,9 @@
  #include <sys/sysctl.h>
  #include <sys/time.h>
  #include <sys/types.h>
+#if !defined(__NetBSD__)
  #include <sys/user.h>
+#endif
  #include <sys/wait.h>
  #include <utime.h>
  #include <poll.h>

$NetBSD$

--- src/VBox/Main/xml/Settings.cpp.orig	2016-03-04 19:29:43.000000000 +0000
+++ src/VBox/Main/xml/Settings.cpp
@@ -5496,10 +5496,10 @@ bool MachineConfigFile::isAudioDriverAll
         case AudioDriverType_Pulse:
 # endif
 #endif /* RT_OS_LINUX */
-#if defined (RT_OS_LINUX) || defined (RT_OS_FREEBSD) || defined(VBOX_WITH_SOLARIS_OSS)
+#if defined (RT_OS_LINUX) || defined (RT_OS_FREEBSD) || defined(VBOX_WITH_SOLARIS_OSS) || defined (RT_OS_NETBSD)
         case AudioDriverType_OSS:
 #endif
-#ifdef RT_OS_FREEBSD
+#if defined (RT_OS_FREEBSD) || defined (RT_OS_NETBSD)
 # ifdef VBOX_WITH_PULSE
         case AudioDriverType_Pulse:
 # endif
@@ -5561,7 +5561,7 @@ AudioDriverType_T MachineConfigFile::get
     return AudioDriverType_CoreAudio;
 #elif defined(RT_OS_OS2)
     return AudioDriverType_MMPM;
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_FREEBSD)
     return AudioDriverType_OSS;
 #else
     return AudioDriverType_Null;

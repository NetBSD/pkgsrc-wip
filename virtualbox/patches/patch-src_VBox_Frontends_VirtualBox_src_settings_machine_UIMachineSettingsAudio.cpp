$NetBSD$

--- src/VBox/Frontends/VirtualBox/src/settings/machine/UIMachineSettingsAudio.cpp.orig	2016-03-04 19:29:15.000000000 +0000
+++ src/VBox/Frontends/VirtualBox/src/settings/machine/UIMachineSettingsAudio.cpp
@@ -159,12 +159,12 @@ void UIMachineSettingsAudio::retranslate
 # endif /* VBOX_WITH_SOLARIS_OSS */
 #endif /* Q_OS_SOLARIS */
 
-#if defined Q_OS_LINUX || defined Q_OS_FREEBSD
+#if defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined(RT_OS_NETBSD)
     m_pComboAudioDriver->setItemText(++iIndex, gpConverter->toString(KAudioDriverType_OSS));
 # ifdef VBOX_WITH_PULSE
     m_pComboAudioDriver->setItemText(++iIndex, gpConverter->toString(KAudioDriverType_Pulse));
 # endif /* VBOX_WITH_PULSE */
-#endif /* Q_OS_LINUX | Q_OS_FREEBSD */
+#endif /* Q_OS_LINUX | Q_OS_FREEBSD || RT_OS_NETBSD */
 
 #ifdef Q_OS_LINUX
 # ifdef VBOX_WITH_ALSA
@@ -227,12 +227,12 @@ void UIMachineSettingsAudio::prepareComb
 # endif /* VBOX_WITH_SOLARIS_OSS */
 #endif /* Q_OS_SOLARIS */
 
-#if defined Q_OS_LINUX || defined Q_OS_FREEBSD
+#if defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined(RT_OS_NETBSD)
     m_pComboAudioDriver->insertItem(++iIndex, "", KAudioDriverType_OSS);
 # ifdef VBOX_WITH_PULSE
     m_pComboAudioDriver->insertItem(++iIndex, "", KAudioDriverType_Pulse);
 # endif /* VBOX_WITH_PULSE */
-#endif /* Q_OS_LINUX | Q_OS_FREEBSD */
+#endif /* Q_OS_LINUX | Q_OS_FREEBSD | RT_OS_NETBSD */
 
 #ifdef Q_OS_LINUX
 # ifdef VBOX_WITH_ALSA
@@ -253,4 +253,3 @@ void UIMachineSettingsAudio::prepareComb
     m_pComboAudioController->insertItem(++iIndex, "", KAudioControllerType_AC97);
     m_pComboAudioController->insertItem(++iIndex, "", KAudioControllerType_SB16);
 }
-

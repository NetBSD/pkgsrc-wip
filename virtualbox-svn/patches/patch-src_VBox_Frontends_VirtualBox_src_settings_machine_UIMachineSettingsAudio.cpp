$NetBSD$

--- src/VBox/Frontends/VirtualBox/src/settings/machine/UIMachineSettingsAudio.cpp.orig	2016-07-10 20:54:24.000000000 +0000
+++ src/VBox/Frontends/VirtualBox/src/settings/machine/UIMachineSettingsAudio.cpp
@@ -232,4 +232,3 @@ void UIMachineSettingsAudio::prepareComb
     m_pComboAudioController->insertItem(++iIndex, "", KAudioControllerType_AC97);
     m_pComboAudioController->insertItem(++iIndex, "", KAudioControllerType_SB16);
 }
-

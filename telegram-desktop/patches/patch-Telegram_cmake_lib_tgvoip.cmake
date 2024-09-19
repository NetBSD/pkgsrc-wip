$NetBSD$

--- Telegram/cmake/lib_tgvoip.cmake.orig	2021-02-17 15:20:05.000000000 +0000
+++ Telegram/cmake/lib_tgvoip.cmake
@@ -79,46 +79,6 @@ if (NOT TGVOIP_FOUND)
         json11.cpp
         json11.hpp
 
-        # Windows
-        os/windows/NetworkSocketWinsock.cpp
-        os/windows/NetworkSocketWinsock.h
-        os/windows/AudioInputWave.cpp
-        os/windows/AudioInputWave.h
-        os/windows/AudioOutputWave.cpp
-        os/windows/AudioOutputWave.h
-        os/windows/AudioOutputWASAPI.cpp
-        os/windows/AudioOutputWASAPI.h
-        os/windows/AudioInputWASAPI.cpp
-        os/windows/AudioInputWASAPI.h
-        os/windows/MinGWSupport.h
-        os/windows/WindowsSpecific.cpp
-        os/windows/WindowsSpecific.h
-
-        # macOS
-        os/darwin/AudioInputAudioUnit.cpp
-        os/darwin/AudioInputAudioUnit.h
-        os/darwin/AudioOutputAudioUnit.cpp
-        os/darwin/AudioOutputAudioUnit.h
-        os/darwin/AudioInputAudioUnitOSX.cpp
-        os/darwin/AudioInputAudioUnitOSX.h
-        os/darwin/AudioOutputAudioUnitOSX.cpp
-        os/darwin/AudioOutputAudioUnitOSX.h
-        os/darwin/AudioUnitIO.cpp
-        os/darwin/AudioUnitIO.h
-        os/darwin/DarwinSpecific.mm
-        os/darwin/DarwinSpecific.h
-
-        # Linux
-        os/linux/AudioInputALSA.cpp
-        os/linux/AudioInputALSA.h
-        os/linux/AudioOutputALSA.cpp
-        os/linux/AudioOutputALSA.h
-        os/linux/AudioOutputPulse.cpp
-        os/linux/AudioOutputPulse.h
-        os/linux/AudioInputPulse.cpp
-        os/linux/AudioInputPulse.h
-        os/linux/AudioPulse.cpp
-        os/linux/AudioPulse.h
 
         # POSIX
         os/posix/NetworkSocketPosix.cpp
@@ -169,6 +129,51 @@ if (NOT TGVOIP_FOUND)
         endif()
     endif()
 
+	if (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD|NetBSD|DragonFly")
+		remove_target_sources(Telegram ${src_loc}
+        # Windows
+        os/windows/NetworkSocketWinsock.cpp
+        os/windows/NetworkSocketWinsock.h
+        os/windows/AudioInputWave.cpp
+        os/windows/AudioInputWave.h
+        os/windows/AudioOutputWave.cpp
+        os/windows/AudioOutputWave.h
+        os/windows/AudioOutputWASAPI.cpp
+        os/windows/AudioOutputWASAPI.h
+        os/windows/AudioInputWASAPI.cpp
+        os/windows/AudioInputWASAPI.h
+        os/windows/MinGWSupport.h
+        os/windows/WindowsSpecific.cpp
+        os/windows/WindowsSpecific.h
+
+        # macOS
+        os/darwin/AudioInputAudioUnit.cpp
+        os/darwin/AudioInputAudioUnit.h
+        os/darwin/AudioOutputAudioUnit.cpp
+        os/darwin/AudioOutputAudioUnit.h
+        os/darwin/AudioInputAudioUnitOSX.cpp
+        os/darwin/AudioInputAudioUnitOSX.h
+        os/darwin/AudioOutputAudioUnitOSX.cpp
+        os/darwin/AudioOutputAudioUnitOSX.h
+        os/darwin/AudioUnitIO.cpp
+        os/darwin/AudioUnitIO.h
+        os/darwin/DarwinSpecific.mm
+        os/darwin/DarwinSpecific.h
+
+        # Linux
+        os/linux/AudioInputALSA.cpp
+        os/linux/AudioInputALSA.h
+        os/linux/AudioOutputALSA.cpp
+        os/linux/AudioOutputALSA.h
+        os/linux/AudioOutputPulse.cpp
+        os/linux/AudioOutputPulse.h
+        os/linux/AudioInputPulse.cpp
+        os/linux/AudioInputPulse.h
+        os/linux/AudioPulse.cpp
+        os/linux/AudioPulse.h
+		)
+	endif()
+
     target_include_directories(lib_tgvoip_bundled
     PUBLIC
         ${tgvoip_loc}
@@ -179,7 +184,7 @@ if (NOT TGVOIP_FOUND)
         desktop-app::external_opus
     )
 
-    if (LINUX)
+    if (LINUX AND NOT (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD|NetBSD|DragonFly"))
         find_package(PkgConfig REQUIRED)
         find_package(ALSA REQUIRED)
         pkg_check_modules(PULSE REQUIRED libpulse)

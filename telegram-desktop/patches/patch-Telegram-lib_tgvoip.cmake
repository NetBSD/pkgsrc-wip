$NetBSD$

--- Telegram/cmake/lib_tgvoip.cmake.orig	2020-01-28 17:45:49.000000000 +0000
+++ Telegram/cmake/lib_tgvoip.cmake
@@ -18,6 +18,35 @@ else()
     init_target(lib_tgvoip)
     add_library(tdesktop::lib_tgvoip ALIAS lib_tgvoip)
 
+	if (TDESKTOP_WITHOUT_PULSE)
+		target_compile_definitions(lib_tgvoip PUBLIC WITHOUT_PULSE)
+	else()
+		nice_target_sources(lib_tgvoip ${tgvoip_loc}
+		PRIVATE
+			# UNIX-like OSes
+			os/linux/AudioOutputPulse.cpp
+        	os/linux/AudioOutputPulse.h
+        	os/linux/AudioInputPulse.cpp
+        	os/linux/AudioInputPulse.h
+        	os/linux/AudioPulse.cpp
+        	os/linux/AudioPulse.h)
+	endif()
+
+
+	if (TDESKTOP_WITHOUT_ALSA)
+		target_compile_definitions(lib_tgvoip PUBLIC WITHOUT_ALSA)
+	else()
+		nice_target_sources(lib_tgvoip ${tgvoip_loc}
+		PRIVATE
+        	# Linux
+        	os/linux/AudioInputALSA.cpp
+        	os/linux/AudioInputALSA.h
+        	os/linux/AudioOutputALSA.cpp
+        	os/linux/AudioOutputALSA.h
+		)
+
+	endif()
+
     if (NOT APPLE)
         # On macOS if you build libtgvoip with C++17 it uses std::optional
         # instead of absl::optional and when it uses optional::value, the
@@ -107,19 +136,6 @@ else()
         os/darwin/AudioUnitIO.h
         os/darwin/DarwinSpecific.mm
         os/darwin/DarwinSpecific.h
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
-
         # POSIX
         os/posix/NetworkSocketPosix.cpp
         os/posix/NetworkSocketPosix.h

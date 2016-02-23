$NetBSD$

Add -lpthread, and remove Linux Joystick and ALSA-related stuff from
the build.

--- Osmose-0-9-96-QT.pro.orig	2011-04-30 13:23:22.000000000 +0000
+++ Osmose-0-9-96-QT.pro
@@ -6,12 +6,11 @@ TEMPLATE = app
 TARGET = 
 DEPENDPATH += . cpu osmose unzip
 INCLUDEPATH += . cpu osmose unzip
-LIBS += -lz -lasound
+LIBS += -lz -lpthread
 QT+=opengl
 
 # Input
 HEADERS += EmulationThread.h \
-           Joystick.h \
            KeyMapper.h \
            OsmoseConfigurationFile.h \
            OsmoseEmulationThread.h \
@@ -40,7 +39,6 @@ HEADERS += EmulationThread.h \
            osmose/SmsDebugger.h \
            osmose/SmsEnvironment.h \
            osmose/SN76489.h \
-           osmose/SoundThread.h \
            osmose/VDP.h \
            osmose/VDP_GG.h \
            osmose/Version.h \
@@ -50,7 +48,6 @@ HEADERS += EmulationThread.h \
            unzip/unzip.h
 FORMS += Configuration.ui LogWindow.ui
 SOURCES += EmulationThread.cpp \
-           Joystick.cpp \
            KeyMapper.cpp \
            main.cpp \
            OsmoseConfigurationFile.cpp \
@@ -80,7 +77,6 @@ SOURCES += EmulationThread.cpp \
            osmose/RomSpecificOption.cpp \
            osmose/SmsEnvironment.cpp \
            osmose/SN76489.cpp \
-           osmose/SoundThread.cpp \
            osmose/VDP.cpp \
            osmose/VDP_GG.cpp \
            osmose/WaveWriter.cpp \

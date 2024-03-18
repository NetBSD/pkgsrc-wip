$NetBSD$

Adapt for portaudio19.
From Debian.

--- gameSource/sound/MusicPlayer.cpp.orig	2006-09-19 17:46:11.000000000 +0000
+++ gameSource/sound/MusicPlayer.cpp
@@ -112,13 +112,14 @@ SoundSamples *MusicPlayer::getMoreMusic(
 
     // get parts and positions of gardeners
     int numParts = 0;
-    Vector3D **positions =
-        globalWorld->getAllGardenerPositions( &numParts );
-    MusicPart **musicParts =
-        globalWorld->getAllGardenerMusicParts( &numParts );
-    double *volumeModifiers =
-        globalWorld->getAllGardenerMusicVolumeModifiers( &numParts );
-
+    Vector3D **positions = NULL;
+    MusicPart **musicParts = NULL;
+    double *volumeModifiers = NULL;
+    if ( globalWorld ){
+        positions = globalWorld->getAllGardenerPositions( &numParts );
+        musicParts = globalWorld->getAllGardenerMusicParts( &numParts );
+        volumeModifiers = globalWorld->getAllGardenerMusicVolumeModifiers( &numParts );
+    }
     
     // get center position from current player position
     Vector3D *centerPosition = new Vector3D( &globalPlayerCurrentPosition );

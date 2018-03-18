$NetBSD$

Search the installation directories for data files.
Create the player data directory.

--- src/WitchBlastGame.cpp.orig	2015-10-29 08:36:26.000000000 +0000
+++ src/WitchBlastGame.cpp
@@ -68,6 +68,7 @@
 #include <ctime>
 #include <iomanip>
 #include <algorithm>
+#include <sys/stat.h>
 
 //#define LEVEL_TEST_MODE
 
@@ -349,7 +350,11 @@ WitchBlastGame::WitchBlastGame()
   };
 
   for (const char *const filename : images)
-    ImageManager::getInstance().addImage(filename);
+  {
+    std::string fullname = WITCHBLAST_DATA_DIR;
+    fullname += filename;
+    ImageManager::getInstance().addImage(fullname.c_str());
+  }
 
   const char *const sounds[] =
   {
@@ -432,14 +437,16 @@ WitchBlastGame::WitchBlastGame()
   SoundManager::getInstance().setVolume(parameters.soundVolume);
   for (const char *const filename : sounds)
   {
-    SoundManager::getInstance().addSound(filename);
+    std::string fullname = WITCHBLAST_DATA_DIR;
+    fullname += filename;
+    SoundManager::getInstance().addSound(fullname.c_str());
   }
 
-  if (font.loadFromFile("media/DejaVuSans-Bold.ttf"))
+  if (font.loadFromFile(WITCHBLAST_DATA_DIR "media/DejaVuSans-Bold.ttf"))
   {
     myText.setFont(font);
   }
-  graphicsFont.loadFromFile("media/Caudex-Bold.ttf");
+  graphicsFont.loadFromFile(WITCHBLAST_DATA_DIR "media/Caudex-Bold.ttf");
 
   miniMap = NULL;
   currentMap = NULL;
@@ -480,6 +487,8 @@ WitchBlastGame::WitchBlastGame()
   scoreState = ScoreOK;
   loopCounter = 0;
 
+  mkdir(PLAYER_DATA.c_str(), 0700);
+
   loadGameData();
   loadHiScores();
   receiveScoreFromServer();
@@ -5544,9 +5553,9 @@ void WitchBlastGame::playMusic(musicEnum
 
       switch (r)
       {
-        case 0: ok = music.openFromFile("media/sound/WitchBlastTheme.ogg"); break;
-        case 1: ok = music.openFromFile("media/sound/SavageLife.ogg"); break;
-        case 2: ok = music.openFromFile("media/sound/HauntedLighthouse.ogg"); break;
+        case 0: ok = music.openFromFile(WITCHBLAST_DATA_DIR "media/sound/WitchBlastTheme.ogg"); break;
+        case 1: ok = music.openFromFile(WITCHBLAST_DATA_DIR "media/sound/SavageLife.ogg"); break;
+        case 2: ok = music.openFromFile(WITCHBLAST_DATA_DIR "media/sound/HauntedLighthouse.ogg"); break;
       }
 
       currentStandardMusic = r;
@@ -5554,19 +5563,19 @@ void WitchBlastGame::playMusic(musicEnum
     break;
 
   case MusicEnding:
-    ok = music.openFromFile("media/sound/AmbiantMedieval.ogg");
+    ok = music.openFromFile(WITCHBLAST_DATA_DIR "media/sound/AmbiantMedieval.ogg");
     break;
 
   case MusicBoss:
-    ok = music.openFromFile("media/sound/ShowMeThePower.ogg");
+    ok = music.openFromFile(WITCHBLAST_DATA_DIR "media/sound/ShowMeThePower.ogg");
     break;
 
   case MusicChallenge:
-    ok = music.openFromFile("media/sound/HellsFire.ogg");
+    ok = music.openFromFile(WITCHBLAST_DATA_DIR "media/sound/HellsFire.ogg");
     break;
 
   case MusicIntro:
-    ok = music.openFromFile("media/sound/WitchBlastTheme.ogg");
+    ok = music.openFromFile(WITCHBLAST_DATA_DIR "media/sound/WitchBlastTheme.ogg");
     break;
   }
 
@@ -5597,7 +5606,7 @@ void WitchBlastGame::updateMusicVolume()
   {
     if (parameters.musicVolume > 0)
     {
-      bool ok = music.openFromFile("media/sound/wb.ogg");
+      bool ok = music.openFromFile(WITCHBLAST_DATA_DIR "media/sound/wb.ogg");
       music.setVolume(parameters.musicVolume * VolumeModifier / 100);
       if (ok) music.play();
     }

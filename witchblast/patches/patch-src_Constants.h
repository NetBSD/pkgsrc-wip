$NetBSD$

Store game data in the user's home directory.
Should we use XDG paths instead?

--- src/Constants.h.orig	2015-10-29 08:36:26.000000000 +0000
+++ src/Constants.h
@@ -22,10 +22,11 @@
 const std::string APP_NAME =      "Witch Blast";
 const std::string APP_VERSION =   "0.7.5";
 
-const std::string CONFIG_FILE =     "config.dat";
-const std::string SAVE_FILE =       "game.sav";
-const std::string SAVE_DATA_FILE =  "data/data.sav";
-const std::string HISCORES_FILE =   "data/scores.dat";
+const std::string PLAYER_DATA =     getenv("HOME") + std::string("/.witchblast/");
+const std::string CONFIG_FILE =     PLAYER_DATA + "config.dat";
+const std::string SAVE_FILE =       PLAYER_DATA + "game.sav";
+const std::string SAVE_DATA_FILE =  PLAYER_DATA + "data.sav";
+const std::string HISCORES_FILE =   PLAYER_DATA + "scores.dat";
 
 const std::string SAVE_VERSION =    "SAVE_0.7";
 const std::string SCORE_VERSION =   "V075";

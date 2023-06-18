$NetBSD$

Add a reset method to work around compile error when assigning
to a struct.

--- TheForceEngine/TFE_DarkForces/darkForcesMain.cpp.orig	2023-05-27 05:02:04.000000000 +0000
+++ TheForceEngine/TFE_DarkForces/darkForcesMain.cpp
@@ -193,6 +193,15 @@ namespace TFE_DarkForces
 		s32   levelIndex       = 0;
 		s32   cutsceneIndex    = 0;
 		JBool abortLevel       = JFALSE;
+		void reset(void) {
+			JBool cutscenesEnabled = JTRUE;
+			JBool localMsgLoaded   = JFALSE;
+			s32   startLevel       = 0;
+			GameState state        = GSTATE_STARTUP_CUTSCENES;
+			s32   levelIndex       = 0;
+			s32   cutsceneIndex    = 0;
+			JBool abortLevel       = JFALSE;
+		}
 	};
 	struct SharedGameState
 	{
@@ -209,6 +218,21 @@ namespace TFE_DarkForces
 		CutsceneState* cutsceneList = nullptr;
 		char customGobName[256] = "";
 		LangHotkeys langKeys;
+		void reset(void) { 
+			GameMessages localMessages = {};
+			GameMessages hotKeyMessages = {};
+			TextureData* diskErrorImg = nullptr;
+			Font* swFont1 = nullptr;
+			Font* mapNumFont = nullptr;
+			SoundSourceId screenShotSndSrc = NULL_SOUND;
+			BriefingList  briefingList = { 0 };
+			JBool gameStarted = JFALSE;
+
+			Task* loadMissionTask = nullptr;
+			CutsceneState* cutsceneList = nullptr;
+			char customGobName[256] = "";
+			LangHotkeys langKeys;
+		}
 	};
 	static RunGameState   s_runGameState = {};
 	static SharedGameState s_sharedState = {};
@@ -375,8 +399,9 @@ namespace TFE_DarkForces
 		TFE_Audio::resume();
 
 		// Reset state.
-		s_sharedState = {};
-		s_runGameState = {};
+
+		s_sharedState.reset();
+		s_runGameState.reset();
 	}
 
 	void DarkForces::pauseGame(bool pause)
@@ -1345,4 +1370,4 @@ namespace TFE_DarkForces
 		}
 		return true;
 	}
-}
\ No newline at end of file
+}

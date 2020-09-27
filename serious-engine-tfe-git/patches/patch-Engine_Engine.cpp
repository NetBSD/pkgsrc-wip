$NetBSD$

By default, the game looks for data at $(dirname executable)/../.
A more reasonable choice is to look for rthe data in the user
directory (or a pkgsrc directory such as share/ssam-tfe/data),
this seems to be easiest choice.

--- Engine/Engine.cpp.orig	2020-09-04 12:08:26.000000000 +0000
+++ Engine/Engine.cpp
@@ -564,6 +564,10 @@ ENGINE_API void SE_InitEngine(const char
   }
   _pConsole->Initialize(_fnmUserDir+_strLogFile+".log", 90, 512);
 
+  // Don't search for data in the executable path,
+  // that is what the user data directory is for.
+  _fnmApplicationPath = _fnmUserDir;
+
   _pAnimStock        = new CStock_CAnimData;
   _pTextureStock     = new CStock_CTextureData;
   _pSoundStock       = new CStock_CSoundData;

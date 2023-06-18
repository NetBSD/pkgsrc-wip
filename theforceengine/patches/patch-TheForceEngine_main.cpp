$NetBSD$

Search for program files in the install prefix.

--- TheForceEngine/main.cpp.orig	2023-05-27 05:02:04.000000000 +0000
+++ TheForceEngine/main.cpp
@@ -515,6 +515,7 @@ int main(int argc, char* argv[])
 	#endif
 
 	// Paths
+	FileUtil::setCurrentDirectory(PROGDATADIR);
 	bool pathsSet = true;
 	pathsSet &= TFE_Paths::setProgramPath();
 	pathsSet &= TFE_Paths::setProgramDataPath("TheForceEngine");
@@ -938,4 +939,4 @@ void parseOption(const char* name, const
 			s_nullAudioDevice = true;
 		}
 	}
-}
\ No newline at end of file
+}

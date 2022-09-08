$NetBSD$

Fix "Cannot find gzdoom.pk3" -- https://github.com/ZDoom/gzdoom/pull/1665

--- src/d_main.cpp.orig	2022-07-04 08:31:18.000000000 +0000
+++ src/d_main.cpp
@@ -3535,6 +3535,8 @@ static int D_DoomMain_Internal (void)
 	std::set_new_handler(NewFailure);
 	const char *batchout = Args->CheckValue("-errorlog");
 	
+	D_DoomInit();
+
 	// [RH] Make sure zdoom.pk3 is always loaded,
 	// as it contains magic stuff we need.
 	wad = BaseFileSearch(BASEWAD, NULL, true, GameConfig);
@@ -3568,8 +3570,6 @@ static int D_DoomMain_Internal (void)
 
 	if (!batchrun) Printf(PRINT_LOG, "%s version %s\n", GAMENAME, GetVersionString());
 
-	D_DoomInit();
-
 	extern void D_ConfirmSendStats();
 	D_ConfirmSendStats();
 

$NetBSD$

New gorilla-audio support

--- src/fmod-studio.c.orig	2020-11-09 09:14:31.000000000 +0000
+++ src/fmod-studio.c
@@ -21,7 +21,7 @@ FMOD_RESULT FMOD_Studio_System_Create(FM
 
 	FMOD_STUDIO_SYSTEM *ret = calloc(sizeof(FMOD_STUDIO_SYSTEM), 1);
 	if (!ret) return FMOD_ERR_INTERNAL;
-	ret->ga.mgr = gau_manager_create_custom(ga_DeviceType_Default, GAU_THREAD_POLICY_MULTI, 4, 512);
+	ret->ga.mgr = gau_manager_create_custom(GaDeviceType_Default, GauThreadPolicy_Single, 4, 512);
 	if (!ret->ga.mgr) return FMOD_ERR_INTERNAL;
 	ret->ga.mixer = gau_manager_mixer(ret->ga.mgr);
 	if (!ret->ga.mixer) return FMOD_ERR_INTERNAL;

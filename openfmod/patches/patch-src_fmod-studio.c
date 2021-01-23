$NetBSD$

New gorilla-audio support

--- src/fmod-studio.c.orig	2020-11-09 09:14:31.000000000 +0000
+++ src/fmod-studio.c
@@ -21,11 +21,11 @@ FMOD_RESULT FMOD_Studio_System_Create(FM
 
 	FMOD_STUDIO_SYSTEM *ret = calloc(sizeof(FMOD_STUDIO_SYSTEM), 1);
 	if (!ret) return FMOD_ERR_INTERNAL;
-	ret->ga.mgr = gau_manager_create_custom(ga_DeviceType_Default, GAU_THREAD_POLICY_MULTI, 4, 512);
+	ret->ga.mgr = GauManager_create_custom(GaDeviceType_Default, GauThreadPolicy_Single, 4, 512);
 	if (!ret->ga.mgr) return FMOD_ERR_INTERNAL;
-	ret->ga.mixer = gau_manager_mixer(ret->ga.mgr);
+	ret->ga.mixer = GauManager_mixer(ret->ga.mgr);
 	if (!ret->ga.mixer) return FMOD_ERR_INTERNAL;
-	ret->ga.stream_mgr = gau_manager_streamManager(ret->ga.mgr);
+	ret->ga.stream_mgr = GauManager_streamManager(ret->ga.mgr);
 
 	*system = ret;
 	return FMOD_OK;
@@ -102,7 +102,7 @@ FMOD_RESULT FMOD_Studio_System_GetVCA(FM
 }
 
 FMOD_RESULT FMOD_Studio_System_Update(FMOD_STUDIO_SYSTEM *system) {
-	gau_manager_update(system->ga.mgr);
+	GauManager_update(system->ga.mgr);
 	return FMOD_OK;
 }
 

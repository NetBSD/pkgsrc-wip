$NetBSD$

Newer gorilla-audio support.

--- include/openfmod-internal.h.orig	2020-11-09 09:14:31.000000000 +0000
+++ include/openfmod-internal.h
@@ -31,7 +31,7 @@ typedef struct {
 
 struct FMOD_SOUND {
 	bool is_mem, is_loaded;
-	ga_Handle *handle;
+	GaHandle *handle;
 	const char *fpath;
 };
 
@@ -65,9 +65,9 @@ FMOD_GUID *path_guid_get(MapPathToGuid *
 
 struct FMOD_STUDIO_SYSTEM {
 	struct {
-		gau_Manager *mgr;
-		ga_Mixer *mixer;
-		ga_StreamManager *stream_mgr;
+		GauManager *mgr;
+		GaMixer *mixer;
+		GaStreamManager *stream_mgr;
 	} ga;
 
 	MapPathToGuid pathmap;

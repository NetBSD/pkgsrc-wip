$NetBSD$

Use installed data path.
Disable rumble/haptic support.

--- seg009.c.orig	2017-02-05 07:38:56.000000000 +0000
+++ seg009.c
@@ -152,7 +152,7 @@ static FILE* open_dat_from_root_or_data_
 	// if failed, try if the DAT file can be opened in the data/ directory, instead of the main folder
 	if (fp == NULL) {
 		char data_path[POP_MAX_PATH];
-		snprintf(data_path, sizeof(data_path), "data/%s", filename);
+		snprintf(data_path, sizeof(data_path), "%s/data/%s", PKGSRC_DATA_PATH, filename);
 
 		// verify that this is a regular file and not a directory (otherwise, don't open)
 		struct stat path_stat;
@@ -1644,7 +1644,7 @@ const int max_sound_id = 58;
 char** sound_names = NULL;
 
 void load_sound_names() {
-	const char* names_path = "data/music/names.txt";
+	const char* names_path = PKGSRC_DATA_PATH "data/music/names.txt";
 	if (sound_names != NULL) return;
 	FILE* fp = fopen(names_path,"rt");
 	if (fp==NULL) return;
@@ -1692,7 +1692,7 @@ sound_buffer_type* load_sound(int index)
 				const char* ext=exts[i];
 				struct stat info;
 
-				snprintf(filename, sizeof(filename), "data/music/%s.%s", sound_name(index), ext);
+				snprintf(filename, sizeof(filename), "%s/data/music/%s.%s", PKGSRC_DATA_PATH, sound_name(index), ext);
 				// Skip nonexistent files:
 				if (stat(filename, &info))
 					continue;
@@ -1933,7 +1933,7 @@ int __pascal far check_sound_playing() {
 // seg009:38ED
 void __pascal far set_gr_mode(byte grmode) {
 	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_NOPARACHUTE |
-				 SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC ) != 0) {
+				 SDL_INIT_GAMECONTROLLER ) != 0) {
 		sdlperror("SDL_Init");
 		quit(1);
 	}
@@ -1957,7 +1957,7 @@ void __pascal far set_gr_mode(byte grmod
 										  pop_window_width, pop_window_height, flags);
 	renderer_ = SDL_CreateRenderer(window_, -1 , SDL_RENDERER_ACCELERATED );
 
-	SDL_Surface* icon = IMG_Load("data/icon.png");
+	SDL_Surface* icon = IMG_Load(PKGSRC_DATA_PATH "data/icon.png");
 	if (icon == NULL) {
 		sdlperror("Could not load icon");
 	} else {
@@ -2109,7 +2109,7 @@ void load_from_opendats_metadata(int res
 			if (len >= 5 && filename_no_ext[len-4] == '.') {
 				filename_no_ext[len-4] = '\0'; // terminate, so ".DAT" is deleted from the filename
 			}
-			snprintf(image_filename,sizeof(image_filename),"data/%s/res%d.%s",filename_no_ext, resource_id, extension);
+			snprintf(image_filename,sizeof(image_filename),"%s/data/%s/res%d.%s", PKGSRC_DATA_PATH, filename_no_ext, resource_id, extension);
 			if (!use_custom_levelset) {
 				//printf("loading (binary) %s",image_filename);
 				fp = fopen(image_filename, "rb");

$NetBSD$

Use installed data path.

--- seg009.c.orig	2016-01-02 13:32:48.000000000 +0000
+++ seg009.c
@@ -116,10 +116,13 @@ int __pascal far pop_wait(int timer_inde
 
 // seg009:0F58
 dat_type *__pascal open_dat(const char *filename,int drive) {
-	FILE* fp = fopen(filename, "rb");
+	char fname[256];
+	FILE* fp;
 	dat_header_type dat_header;
 	dat_table_type* dat_table = NULL;
 
+	snprintf(fname, sizeof(fname), "%s/%s", PKGSRC_DATA_PATH, filename);
+	fp = fopen(fname, "rb");
 	dat_type* pointer = (dat_type*) calloc(1, sizeof(dat_type));
 	strncpy(pointer->filename, filename, sizeof(pointer->filename));
 	pointer->next_dat = dat_chain_ptr;
@@ -1586,7 +1589,7 @@ const int max_sound_id = 58;
 char** sound_names = NULL;
 
 void load_sound_names() {
-	const char const * names_path = "data/music/names.txt";
+	const char const * names_path = PKGSRC_DATA_PATH "data/music/names.txt";
 	if (sound_names != NULL) return;
 	FILE* fp = fopen(names_path,"rt");
 	if (fp==NULL) return;
@@ -1626,7 +1629,7 @@ sound_buffer_type* load_sound(int index)
 				const char* ext=exts[i];
 				struct stat info;
 
-				snprintf(filename, sizeof(filename), "data/music/%s.%s", sound_names[index], ext);
+				snprintf(filename, sizeof(filename), PKGSRC_DATA_PATH "data/music/%s.%s", sound_names[index], ext);
 				// Skip nonexistent files:
 				if (stat(filename, &info))
 					continue;
@@ -1998,7 +2001,7 @@ void load_from_opendats_metadata(int res
 			}
 		} else {
 			// If it's a directory:
-			snprintf(image_filename,sizeof(image_filename),"data/%s/res%d.%s",pointer->filename, resource_id, extension);
+			snprintf(image_filename,sizeof(image_filename),PKGSRC_DATA_PATH "data/%s/res%d.%s",pointer->filename, resource_id, extension);
 			//printf("loading (binary) %s",image_filename);
 			fp = fopen(image_filename, "rb");
 			if (fp != NULL) {

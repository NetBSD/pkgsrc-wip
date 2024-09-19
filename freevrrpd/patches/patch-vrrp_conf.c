$NetBSD$

Fix bogus condition - fpos_t is an opaque struct, not an integer. And
if the intent was to make sure we are at the beginning of the input
stream, ftell(3) is the better choice.

--- vrrp_conf.c.orig	2015-02-04 00:39:49.000000000 +0000
+++ vrrp_conf.c
@@ -173,11 +173,9 @@ vrrp_conf_lecture_fichier(struct vrrp_vr
 	char          **temp3;
 	char            option[1024], arg[1024];
 	int             i, j;
-	fpos_t          pos;
 	int		optok;
 
-	fgetpos(stream, &pos);
-	if (!pos) {
+	if (0 == ftell(stream)) {
 		while (ligne[0] == '#' || ligne[0] == 0 || ligne[0] == '\n')
 			fgets(ligne, 1024, stream);
 		if (strncmp(ligne, "[VRID]", 6)) {

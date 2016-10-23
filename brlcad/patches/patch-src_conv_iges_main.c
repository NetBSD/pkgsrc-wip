$NetBSD$

Fix invalid memory read. ntypes is referenced via iges_extern.h as size_t and
it results in corrupted reads.

--- src/conv/iges/main.c.orig	2016-08-09 06:48:19.000000000 +0000
+++ src/conv/iges/main.c
@@ -41,7 +41,8 @@ size_t totentities, dirarraylen;
 FILE *fd;
 struct rt_wdb *fdout;
 char brlcad_file[256];
-int reclen, currec, ntypes;
+int reclen, currec;
+size_t ntypes;
 int brlcad_att_de = 0;
 struct iges_directory **dir;
 struct reglist *regroot;

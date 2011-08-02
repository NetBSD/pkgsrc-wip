$NetBSD: patch-src_msgfile.c,v 1.1 2011/08/02 22:19:13 khorben Exp $

--- src/msgfile.c.orig	2010-11-01 08:36:44.000000000 +0000
+++ src/msgfile.c
@@ -28,6 +28,8 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
+#include <stdlib.h>
+#include <stdio.h>
 #include <string.h>
 
 static struct msg_entry *alloc_entry(struct msg_entries *entries,
@@ -111,7 +113,14 @@ struct msg_entries *msg_entry_parse(void
 
 	n = 2342;
 	line = NULL;
+#ifdef __linux__
         while (getline(&line, &n, file) != -1) {
+#else
+	/* XXX probably not completely equivalent */
+	while( (line = malloc(2343)) != NULL
+			&& fgets(line, 2343, file) != NULL) {
+		n = strlen(line);
+#endif
 		handle_line(entries, line);
 		free(line);
 		line = NULL;

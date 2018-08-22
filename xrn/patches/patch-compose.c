$NetBSD$

Inlcude missing system header file.
Don't use data as format string in sprintf().
Typecast parameter of variadic function execl().

--- compose.c.orig	2010-02-03 17:54:24.000000000 +0000
+++ compose.c
@@ -40,6 +40,7 @@ static char XRNrcsid[] = "$Id: compose.c
 #include <ctype.h>
 #include <errno.h>
 #include <sys/file.h>
+#include <stdlib.h>
 #include <signal.h>
 #include <assert.h>
 #include "error_hnds.h"
@@ -1936,7 +1937,7 @@ getIncludedArticleText()
 
      if (PostingMode == FORWARD) {
 	 int line_size;
-       (void) sprintf(input, FORWARDED_ARTICLE_END_MSG);
+       (void) sprintf(input, "%s", FORWARDED_ARTICLE_END_MSG);
 	 line_size = strlen(input);
 	 if (prefix_size + line_size > size - cur_size - 1) {
 	     /* See above */
@@ -2369,7 +2370,7 @@ Call_Editor(
 	    for (i = 3; i < maxdesc; i++) {
 		(void) close(i);
 	    }
-	    (void) execl("/bin/sh", "sh", "-c", buffer, 0);
+	    (void) execl("/bin/sh", "sh", "-c", buffer, (const char *)NULL);
           (void) fprintf(stderr, ERROR_EXEC_FAILED_MSG, buffer);
 	    (void) _exit(127);
 	}

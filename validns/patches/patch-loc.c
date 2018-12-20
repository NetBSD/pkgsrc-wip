$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- loc.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ loc.c
@@ -64,7 +64,7 @@ static struct rr *loc_parse(char *name, 
     deg = i;
     min = 0;
     sec = 0;
-    if (isdigit(*s)) {
+    if (isdigit((unsigned char)*s)) {
         i = extract_integer(&s, "minutes latitude", NULL);
         if (i < 0)
             return NULL;
@@ -72,7 +72,7 @@ static struct rr *loc_parse(char *name, 
             return bitch("minutes latitude not in the range 0..59");
         min = i;
 
-        if (isdigit(*s)) { /* restricted floating point, starting with a digit */
+        if (isdigit((unsigned char)*s)) { /* restricted floating point, starting with a digit */
             if (extract_double(&s, "seconds latitude", &sec, 0) < 0)
                 return NULL;
             if (sec < 0 || sec > 59.999)
@@ -89,7 +89,7 @@ static struct rr *loc_parse(char *name, 
     } else {
         return bitch("latitude: N or S is expected");
     }
-    if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
         return bitch("latitude: N or S is expected");
     }
     s = skip_white_space(s);
@@ -104,7 +104,7 @@ static struct rr *loc_parse(char *name, 
     deg = i;
     min = 0;
     sec = 0;
-    if (isdigit(*s)) {
+    if (isdigit((unsigned char)*s)) {
         i = extract_integer(&s, "minutes longitude", NULL);
         if (i < 0)
             return NULL;
@@ -112,7 +112,7 @@ static struct rr *loc_parse(char *name, 
             return bitch("minutes longitude not in the range 0..59");
         min = i;
 
-        if (isdigit(*s)) { /* restricted floating point, starting with a digit */
+        if (isdigit((unsigned char)*s)) { /* restricted floating point, starting with a digit */
             if (extract_double(&s, "seconds longitude", &sec, 0) < 0)
                 return NULL;
             if (sec < 0 || sec > 59.999)
@@ -129,7 +129,7 @@ static struct rr *loc_parse(char *name, 
     } else {
         return bitch("longitude: E or W is expected");
     }
-    if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
         return bitch("longitude: E or W is expected");
     }
     s = skip_white_space(s);

$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- main.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ main.c
@@ -109,8 +109,8 @@ static char *process_directive(char *s)
     if (*(s+1) == 'O' && strncmp(s, "$ORIGIN", 7) == 0) {
         char *o;
         s += 7;
-        if (!isspace(*s)) {
-            if (isalnum(*s)) goto unrecognized_directive;
+        if (!isspace((unsigned char)*s)) {
+            if (isalnum((unsigned char)*s)) goto unrecognized_directive;
             return bitch("bad $ORIGIN format");
         }
         s = skip_white_space(s);
@@ -128,8 +128,8 @@ static char *process_directive(char *s)
         }
     } else if (*(s+1) == 'T' && strncmp(s, "$TTL", 4) == 0) {
         s += 4;
-        if (!isspace(*s)) {
-            if (isalnum(*s)) goto unrecognized_directive;
+        if (!isspace((unsigned char)*s)) {
+            if (isalnum((unsigned char)*s)) goto unrecognized_directive;
             return bitch("bad $TTL format");
         }
         s = skip_white_space(s);
@@ -149,8 +149,8 @@ static char *process_directive(char *s)
         char *lhs, *rdtype;
 
         s += 9;
-        if (!isspace(*s)) {
-            if (isalnum(*s)) goto unrecognized_directive;
+        if (!isspace((unsigned char)*s)) {
+            if (isalnum((unsigned char)*s)) goto unrecognized_directive;
             return bitch("bad $GENERATE format");
         }
         s = skip_white_space(s);
@@ -190,13 +190,13 @@ static char *process_directive(char *s)
         char *p, *f;
         char c;
         s += 8;
-        if (!isspace(*s)) {
-            if (isalnum(*s)) goto unrecognized_directive;
+        if (!isspace((unsigned char)*s)) {
+            if (isalnum((unsigned char)*s)) goto unrecognized_directive;
             return bitch("bad $INCLUDE format");
         }
         s = skip_white_space(s);
         p = s;
-        while (*s && !isspace(*s) && *s != ';')
+        while (*s && !isspace((unsigned char)*s) && *s != ';')
             s++;
         c = *s;
         *s = '\0';
@@ -221,7 +221,7 @@ static char *process_directive(char *s)
     } else {
 unrecognized_directive:
         s = d-1;
-        while (isalnum(*d)) d++;
+        while (isalnum((unsigned char)*d)) d++;
         *d = '\0';
         return bitch("unrecognized directive: %s", s);
     }
@@ -276,7 +276,7 @@ read_zone_file(void)
                 continue;
 
             s = file_info->buf;
-            if (!isspace(*s)) {
+            if (!isspace((unsigned char)*s)) {
                 /* <domain-name>, $INCLUDE, $ORIGIN */
                 if (*s == '$') {
                     process_directive(s);
@@ -298,7 +298,7 @@ read_zone_file(void)
             }
             if (G.default_ttl >= 0)
                 ttl = G.default_ttl;
-            if (isdigit(*s)) {
+            if (isdigit((unsigned char)*s)) {
                 ttl = extract_timevalue(&s, "TTL");
                 if (ttl < 0)
                     continue;
@@ -323,7 +323,7 @@ read_zone_file(void)
                 if (!class)
                     continue;
                 if (*class == 'i' && *(class+1) == 'n' && *(class+2) == 0) {
-                    if (isdigit(*s)) {
+                    if (isdigit((unsigned char)*s)) {
                         ttl = extract_timevalue(&s, "TTL");
                         if (ttl < 0)
                             continue;

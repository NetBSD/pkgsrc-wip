$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- textparse.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ textparse.c
@@ -26,7 +26,7 @@
 
 int empty_line_or_comment(char *s)
 {
-    while (isspace(*s)) s++;
+    while (isspace((unsigned char)*s)) s++;
     if (!*s) return 1;
     if (*s == ';')  return 1;
     return 0;
@@ -34,7 +34,7 @@ int empty_line_or_comment(char *s)
 
 char *skip_white_space(char *s)
 {
-    while (isspace(*s)) s++;
+    while (isspace((unsigned char)*s)) s++;
     if (*s == ';') {
         while (*s) s++;
     }
@@ -76,20 +76,20 @@ static char *extract_name_slow(char **in
     int d, l, ol;
 
     while (1) {
-        if (isalnum(*s) || *s == '_' || *s == '.' || *s == '-' || *s == '/' || ((options & DOLLAR_OK_IN_NAMES) && *s == '$')) {
+        if (isalnum((unsigned char)*s) || *s == '_' || *s == '.' || *s == '-' || *s == '/' || ((options & DOLLAR_OK_IN_NAMES) && *s == '$')) {
             if (t-buf >= 1022)
                 return bitch("name too long");
             *t++ = *s++;
         } else if (*s == '\\') {
             s++;
-            if (isdigit(*s)) {
+            if (isdigit((unsigned char)*s)) {
                 d = *s - '0';
                 s++;
-                if (!isdigit(*s))
+                if (!isdigit((unsigned char)*s))
                     return bitch("bad escape sequence");
                 d = d*10 + *s - '0';
                 s++;
-                if (!isdigit(*s))
+                if (!isdigit((unsigned char)*s))
                     return bitch("bad escape sequence");
                 d = d*10 + *s - '0';
                 s++;
@@ -114,7 +114,7 @@ static char *extract_name_slow(char **in
             break;
         }
     }
-    if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
         return bitch("%s is not valid", what);
     }
     *t = '\0';
@@ -154,7 +154,7 @@ static char *extract_name_slow(char **in
     if (!(options & KEEP_CAPITALIZATION)) {
         t = buf;
         while (*t) {
-            *t = tolower(*t);
+            *t = tolower((unsigned char)*t);
             t++;
         }
     }
@@ -173,7 +173,7 @@ char *extract_name(char **input, char *w
 
     if (*s == '@') {
         s++;
-        if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+        if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
             return bitch("literal @ in %s is not all by itself", what);
         }
         if (!file_info->current_origin) {
@@ -181,7 +181,7 @@ char *extract_name(char **input, char *w
         }
         r = quickstrdup(file_info->current_origin);
     } else {
-        if (!(isalnum(*s) || *s == '_' || *s == '.' || *s == '/' || ((options & DOLLAR_OK_IN_NAMES) && *s == '$'))) {
+        if (!(isalnum((unsigned char)*s) || *s == '_' || *s == '.' || *s == '/' || ((options & DOLLAR_OK_IN_NAMES) && *s == '$'))) {
             if (*s == '*') {
                 wildcard = 1;
             } else {
@@ -191,9 +191,9 @@ char *extract_name(char **input, char *w
             }
         }
         s++;
-        while (isalnum(*s) || *s == '.' || *s == '-' || *s == '_' || *s == '/' || ((options & DOLLAR_OK_IN_NAMES) && *s == '$'))
+        while (isalnum((unsigned char)*s) || *s == '.' || *s == '-' || *s == '_' || *s == '/' || ((options & DOLLAR_OK_IN_NAMES) && *s == '$'))
             s++;
-        if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+        if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
             if (*s == '\\')
                 return extract_name_slow(input, what, options);
             return bitch("%s is not valid", what);
@@ -226,7 +226,7 @@ char *extract_name(char **input, char *w
     if (!(options & KEEP_CAPITALIZATION)) {
         s = r;
         while (*s) {
-            *s = tolower(*s);
+            *s = tolower((unsigned char)*s);
             s++;
         }
     }
@@ -244,13 +244,13 @@ char *extract_label(char **input, char *
     char *r = NULL;
     char *end = NULL;
 
-    if (!isalpha(*s)) {
+    if (!isalpha((unsigned char)*s)) {
         return bitch("%s expected", what);
     }
     s++;
-    while (isalnum(*s))
+    while (isalnum((unsigned char)*s))
         s++;
-    if (*s && !isspace(*s)) {
+    if (*s && !isspace((unsigned char)*s)) {
         return bitch("%s is not valid", what);
     }
     if (!*s)    end = s;
@@ -270,7 +270,7 @@ char *extract_label(char **input, char *
     }
     s = r;
     while (*s) {
-        *s = tolower(*s);
+        *s = tolower((unsigned char)*s);
         s++;
     }
     return r;
@@ -283,14 +283,14 @@ long long extract_integer(char **input, 
     char *end = NULL;
     char c;
 
-    if (!isdigit(*s)) {
+    if (!isdigit((unsigned char)*s)) {
         bitch("%s expected", what);
         return -1;
     }
     s++;
-    while (isdigit(*s))
+    while (isdigit((unsigned char)*s))
         s++;
-    if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
         if (!extra_delimiters || strchr(extra_delimiters, *s) == NULL) {
             bitch("%s is not valid", what);
             return -1;
@@ -320,9 +320,9 @@ int extract_double(char **input, char *w
     char c;
     int saw_m = 0;
 
-    while (isdigit(*s) || *s == '+' || *s == '-' || *s == '.')
+    while (isdigit((unsigned char)*s) || *s == '+' || *s == '-' || *s == '.')
         s++;
-    if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
         if (skip_m && (*s == 'm' || *s == 'M')) {
             saw_m = 1;
         } else {
@@ -343,7 +343,7 @@ int extract_double(char **input, char *w
 
     if (saw_m) {
         s++;
-        if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+        if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
             bitch("%s is not valid", what);
             return -1;
         }
@@ -364,36 +364,36 @@ long extract_timevalue(char **input, cha
     char *s = *input;
     int r = 0, acc = 0;
 
-    if (!isdigit(*s)) {
+    if (!isdigit((unsigned char)*s)) {
         bitch("%s expected", what);
         return -1;
     }
 next_component:
     r = 0;
-    while (isdigit(*s)) {
+    while (isdigit((unsigned char)*s)) {
         r *= 10;
         r += *s - '0';
         s++;
     }
-    if (tolower(*s) == 's') {
+    if (tolower((unsigned char)*s) == 's') {
         s++;
-    } else if (tolower(*s) == 'm') {
+    } else if (tolower((unsigned char)*s) == 'm') {
         r *= 60;
         s++;
-    } else if (tolower(*s) == 'h') {
+    } else if (tolower((unsigned char)*s) == 'h') {
         r *= 3600;
         s++;
-    } else if (tolower(*s) == 'd') {
+    } else if (tolower((unsigned char)*s) == 'd') {
         r *= 86400;
         s++;
-    } else if (tolower(*s) == 'w') {
+    } else if (tolower((unsigned char)*s) == 'w') {
         r *= 604800;
         s++;
     }
     acc += r;
-    if (isdigit(*s)) goto next_component;
+    if (isdigit((unsigned char)*s)) goto next_component;
 
-    if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
         bitch("%s is not valid", what);
         return -1;
     }
@@ -415,66 +415,66 @@ long long extract_timestamp(char **input
     long long epoch = 0;
     struct tm tm;
 
-    if (!isdigit(*s)) {
+    if (!isdigit((unsigned char)*s)) {
         bitch("%s expected", what);
         return -1;
     }
     year = year*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     year = year*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     year = year*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     year = year*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     month = month*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     month = month*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     day = day*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     day = day*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     hour = hour*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     hour = hour*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     minute = minute*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     minute = minute*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     second = second*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (!isdigit(*s)) goto looks_like_epoch;
+    if (!isdigit((unsigned char)*s)) goto looks_like_epoch;
     second = second*10 + *s - '0';
     epoch = epoch*10 + *s - '0';
     s++;
-    if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
         bitch("%s is not valid", what);
         return -1;
     }
@@ -500,7 +500,7 @@ long long extract_timestamp(char **input
     goto done;
 
 looks_like_epoch:
-    if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
         bitch("%s is not valid", what);
         return -1;
     }
@@ -516,14 +516,14 @@ int extract_ipv4(char **input, char *wha
     char *s = *input;
     char c;
 
-    while (isdigit(*s) || *s == '.') {
+    while (isdigit((unsigned char)*s) || *s == '.') {
         s++;
     }
     if (s == *input) {
         bitch("%s is not valid", what);
         return -1;
     }
-    if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
         bitch("%s is not valid", what);
         return -1;
     }
@@ -547,7 +547,7 @@ int extract_ipv6(char **input, char *wha
     char *s = *input;
     char c;
 
-    while (isdigit(*s) || *s == ':' || *s == '.' ||
+    while (isdigit((unsigned char)*s) || *s == ':' || *s == '.' ||
           (*s >= 'a' && *s <= 'f') || (*s >= 'A' && *s <= 'F'))
     {
         s++;
@@ -556,7 +556,7 @@ int extract_ipv6(char **input, char *wha
         bitch("%s is not valid", what);
         return -1;
     }
-    if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
         bitch("%s is not valid", what);
         return -1;
     }
@@ -581,10 +581,10 @@ int extract_u64(char **input, char *what
     uint8_t result = 0;
     unsigned u;
 
-    #define GETHEXBLOCK if (!isxdigit(*s)) { bitch("%s is not valid", what); return -1; } \
+    #define GETHEXBLOCK if (!isxdigit((unsigned char)*s)) { bitch("%s is not valid", what); return -1; } \
         u = 0; \
-        while (isxdigit(*s)) { \
-            if (isdigit(*s)) { \
+        while (isxdigit((unsigned char)*s)) { \
+            if (isdigit((unsigned char)*s)) { \
                 u = (u << 4) | (*s - '0'); \
             } else if (*s >= 'a' && *s <= 'f') { \
                 u = (u << 4) | (*s - 'a' + 10); \
@@ -606,7 +606,7 @@ int extract_u64(char **input, char *what
     #undef GETHEXBLOCK
     #undef SKIPCOLON
 
-    if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
         bitch("%s is not valid", what);
         return -1;
     }
@@ -647,7 +647,7 @@ dump_binary_data(FILE *f, struct binary_
         for (i = 0; i < 16 && mem_len > 0; i++, mem_len--, s++) {
             o[pos[i]] = hex[*s >> 4];
             o[pos[i]+1] = hex[*s & 0x0f];
-            o[51+i] = isprint(*s) ? *s : '.';
+            o[51+i] = isprint((unsigned char)*s) ? *s : '.';
         }
         fprintf(f, "%s", o);
     }
@@ -662,11 +662,11 @@ struct binary_data extract_base64_binary
     int bl;
 
     while (s && *s) {
-        if (!isalnum(*s) && *s != '=' && *s != '+' && *s != '/') {
+        if (!isalnum((unsigned char)*s) && *s != '=' && *s != '+' && *s != '/') {
             bitch("%s expected", what);
             return r;
         }
-        while (isalnum(*s) || *s == '=' || *s == '+' || *s == '/') {
+        while (isalnum((unsigned char)*s) || *s == '=' || *s == '+' || *s == '/') {
             if (l64 >= 4095) {
                 bitch("%s is too long", what);
                 return r;
@@ -737,7 +737,7 @@ struct binary_data extract_text(char **i
     int c;
 
     if (*s != '"') {
-        while (*s && !isspace(*s)) {
+        while (*s && !isspace((unsigned char)*s)) {
             o[l++] = *s++;
         }
         *input = skip_white_space(s);
@@ -758,9 +758,9 @@ more_text:
             if (*s == 0) {
                 bitch("bad backslash quoting of %s", what);
                 return r;
-            } else if (isdigit(*s)) {
+            } else if (isdigit((unsigned char)*s)) {
                 c = 0;
-                while (isdigit(*s)) {
+                while (isdigit((unsigned char)*s)) {
                     c = c*10 + *s - '0';
                     s++;
                 }
@@ -814,7 +814,7 @@ struct binary_data extract_hex_binary_da
     if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
         s += 2;
     if (eat_whitespace == EXTRACT_DONT_EAT_WHITESPACE) {
-        while (isxdigit(*s)) {
+        while (isxdigit((unsigned char)*s)) {
             if (hl >= 4095) {
                 bitch("%s is too long", what);
                 return r;
@@ -823,18 +823,18 @@ struct binary_data extract_hex_binary_da
             s++;
             hl++;
         }
-        if (*s && !isspace(*s) && *s != ';' && *s != ')') {
+        if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')') {
             bitch("%s is not valid", what);
             return r;
         }
         *input = skip_white_space(s);
     } else if (eat_whitespace == EXTRACT_EAT_WHITESPACE) {
         while (s && *s) {
-            if (!isxdigit(*s)) {
+            if (!isxdigit((unsigned char)*s)) {
                 bitch("%s expected", what);
                 return r;
             }
-            while (isxdigit(*s)) {
+            while (isxdigit((unsigned char)*s)) {
                 if (hl >= 4095) {
                     bitch("%s is too long", what);
                     return r;
@@ -859,7 +859,7 @@ struct binary_data extract_hex_binary_da
     memset(r.data, 0, r.length);
     for (hi = 0; hi < hl-hb; hi++) {
         r.data[hi/2] <<= 4;
-        r.data[hi/2] |= 0x0f & (isdigit(hex[hi+hb]) ? hex[hi+hb] - '0' : tolower(hex[hi+hb]) - 'a' + 10);
+        r.data[hi/2] |= 0x0f & (isdigit((unsigned char)hex[hi+hb]) ? hex[hi+hb] - '0' : tolower((unsigned char)hex[hi+hb]) - 'a' + 10);
     }
     return r;
 }

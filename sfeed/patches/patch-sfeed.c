$NetBSD$

Avoid possible UBs in ctype(3) functions.

--- sfeed.c.orig	2018-09-07 16:16:51.071550475 +0000
+++ sfeed.c
@@ -247,10 +247,10 @@ string_print_encoded(String *s)
 		return;
 
 	/* skip leading whitespace */
-	for (p = s->data; *p && isspace((int)*p); p++)
+	for (p = s->data; *p && isspace((unsigned char)*p); p++)
 		;
 	/* seek location of trailing whitespace */
-	for (e = s->data + s->len; e > p && isspace((int)*(e - 1)); e--)
+	for (e = s->data + s->len; e > p && isspace((unsigned char)*(e - 1)); e--)
 		;
 
 	for (; *p && p != e; p++) {
@@ -260,7 +260,7 @@ string_print_encoded(String *s)
 		case '\t': fputs("\\t",  stdout); break;
 		default:
 			/* ignore control chars */
-			if (!iscntrl((int)*p))
+			if (!iscntrl((unsigned char)*p))
 				putchar(*p);
 			break;
 		}
@@ -278,16 +278,16 @@ string_print_trimmed(String *s)
 		return;
 
 	/* skip leading whitespace */
-	for (p = s->data; *p && isspace((int)*p); p++)
+	for (p = s->data; *p && isspace((unsigned char)*p); p++)
 		;
 	/* seek location of trailing whitespace */
-	for (e = s->data + s->len; e > p && isspace((int)*(e - 1)); e--)
+	for (e = s->data + s->len; e > p && isspace((unsigned char)*(e - 1)); e--)
 		;
 
 	for (; *p && p != e; p++) {
-		if (isspace((int)*p))
+		if (isspace((unsigned char)*p))
 			putchar(' '); /* any whitespace to space */
-		else if (!iscntrl((int)*p))
+		else if (!iscntrl((unsigned char)*p))
 			/* ignore other control chars */
 			putchar((int)*p);
 	}
@@ -376,20 +376,20 @@ gettzoffset(const char *s)
 	int tzhour = 0, tzmin = 0;
 	size_t i, namelen;
 
-	for (; *s && isspace((int)*s); s++)
+	for (; *s && isspace((unsigned char)*s); s++)
 		;
 	switch (s[0]) {
 	case '-': /* offset */
 	case '+':
-		for (i = 0, p = s + 1; i < 2 && *p && isdigit(*p); i++, p++)
+		for (i = 0, p = s + 1; i < 2 && *p && isdigit((unsigned char)*p); i++, p++)
 			tzhour = (tzhour * 10) + (*p - '0');
-		if (*p && !isdigit(*p))
+		if (*p && !isdigit((unsigned char)*p))
 			p++;
-		for (i = 0; i < 2 && *p && isdigit(*p); i++, p++)
+		for (i = 0; i < 2 && *p && isdigit((unsigned char)*p); i++, p++)
 			tzmin = (tzmin * 10) + (*p - '0');
 		return ((tzhour * 3600) + (tzmin * 60)) * (s[0] == '-' ? -1 : 1);
 	default: /* timezone name */
-		for (i = 0; *s && isalpha((int)s[i]); i++)
+		for (i = 0; *s && isalpha((unsigned char)s[i]); i++)
 			;
 		namelen = i; /* end of name */
 		/* optimization: these are always non-matching */
@@ -429,49 +429,49 @@ parsetime(const char *s, time_t *tp)
 	int va[6] = { 0 }, i, j, v, vi;
 	size_t m;
 
-	for (; *s && isspace((int)*s); s++)
+	for (; *s && isspace((unsigned char)*s); s++)
 		;
-	if (!isdigit((int)*s) && !isalpha((int)*s))
+	if (!isdigit((unsigned char)*s) && !isalpha((unsigned char)*s))
 		return -1;
 
-	if (isdigit((int)*s)) {
+	if (isdigit((unsigned char)*s)) {
 		/* format "%Y-%m-%d %H:%M:%S" or "%Y-%m-%dT%H:%M:%S" */
 		vi = 0;
 time:
 		for (; *s && vi < 6; vi++) {
-			for (i = 0, v = 0; *s && i < 4 && isdigit((int)*s); s++, i++)
+			for (i = 0, v = 0; *s && i < 4 && isdigit((unsigned char)*s); s++, i++)
 				v = (v * 10) + (*s - '0');
 			va[vi] = v;
 			if ((vi < 2 && *s == '-') ||
-			    (vi == 2 && (*s == 'T' || isspace((int)*s))) ||
+			    (vi == 2 && (*s == 'T' || isspace((unsigned char)*s))) ||
 			    (vi > 2 && *s == ':'))
 				s++;
 		}
 		/* TODO: only if seconds are parsed (vi == 5)? */
 		/* skip milliseconds for: %Y-%m-%dT%H:%M:%S.000Z */
 		if (*s == '.') {
-			for (s++; *s && isdigit((int)*s); s++)
+			for (s++; *s && isdigit((unsigned char)*s); s++)
 				;
 		}
 		end = s;
-	} else if (isalpha((int)*s)) {
+	} else if (isalpha((unsigned char)*s)) {
 		/* format: "%a, %d %b %Y %H:%M:%S" */
 		/* parse "%a, %d %b %Y " part, then use time parsing as above */
-		for (; *s && isalpha((int)*s); s++)
+		for (; *s && isalpha((unsigned char)*s); s++)
 			;
-		for (; *s && isspace((int)*s); s++)
+		for (; *s && isspace((unsigned char)*s); s++)
 			;
 		if (*s != ',')
 			return -1;
-		for (s++; *s && isspace((int)*s); s++)
+		for (s++; *s && isspace((unsigned char)*s); s++)
 			;
-		for (v = 0, i = 0; *s && i < 4 && isdigit((int)*s); s++, i++)
+		for (v = 0, i = 0; *s && i < 4 && isdigit((unsigned char)*s); s++, i++)
 			v = (v * 10) + (*s - '0');
 		va[2] = v; /* day */
-		for (; *s && isspace((int)*s); s++)
+		for (; *s && isspace((unsigned char)*s); s++)
 			;
 		/* end of word month */
-		for (j = 0; *s && isalpha((int)s[j]); j++)
+		for (j = 0; *s && isalpha((unsigned char)s[j]); j++)
 			;
 		/* check month name */
 		if (j < 3 || j > 9)
@@ -487,12 +487,12 @@ time:
 		}
 		if (m >= 12)
 			return -1; /* no month found */
-		for (; *s && isspace((int)*s); s++)
+		for (; *s && isspace((unsigned char)*s); s++)
 			;
-		for (v = 0, i = 0; *s && i < 4 && isdigit((int)*s); s++, i++)
+		for (v = 0, i = 0; *s && i < 4 && isdigit((unsigned char)*s); s++, i++)
 			v = (v * 10) + (*s - '0');
 		va[0] = v; /* year */
-		for (; *s && isspace((int)*s); s++)
+		for (; *s && isspace((unsigned char)*s); s++)
 			;
 		/* parse regular time, see above */
 		vi = 3;

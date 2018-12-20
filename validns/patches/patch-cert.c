$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- cert.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ cert.c
@@ -29,7 +29,7 @@ static int extract_certificate_type(char
     int type;
     char *str_type;
 
-    if (isdigit(**s)) {
+    if (isdigit((unsigned char)**s)) {
         type = extract_integer(s, what, NULL);
         if (type >= 1 && type <= 8)
             return type;
@@ -90,7 +90,7 @@ static struct rr* cert_parse(char *name,
         return bitch("bad key tag");
     rr->key_tag = key_tag;
 
-    if (isdigit(*s)) {
+    if (isdigit((unsigned char)*s)) {
         alg = extract_integer(&s, "algorithm", NULL);
         if (alg < 0)    return NULL;
         if (alg > 255)  return bitch("bad algorithm");

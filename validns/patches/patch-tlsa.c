$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- tlsa.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ tlsa.c
@@ -105,7 +105,7 @@ not_a_prefixed_domain_name:
             return moan(rr->file_name, rr->line, "not a proper prefixed DNS domain name");
         }
         s++;
-        while (isdigit(*s)) {
+        while (isdigit((unsigned char)*s)) {
             port = port * 10  + *s - '0';
             s++;
         }
@@ -134,7 +134,7 @@ static void* smimea_validate_set(struct 
 
         /* c93f1e400f26708f98cb19d936620da35eec8f72e57f9eec01c1afd6._smimecert.example.com. */
         s = named_rr->name;
-        while (isxdigit(*s)) {
+        while (isxdigit((unsigned char)*s)) {
             hash_len++;
             s++;
         }

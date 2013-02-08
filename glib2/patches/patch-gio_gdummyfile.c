$NetBSD: patch-gio_gdummyfile.c,v 1.1 2013/02/08 03:20:55 outpaddling Exp $

--- gio/gdummyfile.c.orig	2012-11-20 14:27:01.000000000 +0000
+++ gio/gdummyfile.c
@@ -446,7 +446,7 @@ unescape_string (const gchar *escaped_st
 		 const gchar *escaped_string_end,
 		 const gchar *illegal_characters)
 {
-  const gchar *in;
+  const gchar *inp;
   gchar *out, *result;
   gint character;
   
@@ -459,19 +459,19 @@ unescape_string (const gchar *escaped_st
   result = g_malloc (escaped_string_end - escaped_string + 1);
 	
   out = result;
-  for (in = escaped_string; in < escaped_string_end; in++) 
+  for (inp = escaped_string; inp < escaped_string_end; inp++) 
     {
-      character = *in;
-      if (*in == '%') 
+      character = *inp;
+      if (*inp == '%') 
         {
-          in++;
-          if (escaped_string_end - in < 2)
+          inp++;
+          if (escaped_string_end - inp < 2)
 	    {
 	      g_free (result);
 	      return NULL;
 	    }
       
-          character = unescape_character (in);
+          character = unescape_character (inp);
       
           /* Check for an illegal character. We consider '\0' illegal here. */
           if (character <= 0 ||
@@ -481,7 +481,7 @@ unescape_string (const gchar *escaped_st
 	      g_free (result);
 	      return NULL;
 	    }
-          in++; /* The other char will be eaten in the loop header */
+          inp++; /* The other char will be eaten in the loop header */
         }
       *out++ = (char)character;
     }
@@ -521,7 +521,7 @@ GDecodedUri *
 _g_decode_uri (const char *uri)
 {
   GDecodedUri *decoded;
-  const char *p, *in, *hier_part_start, *hier_part_end, *query_start, *fragment_start;
+  const char *p, *inp, *hier_part_start, *hier_part_end, *query_start, *fragment_start;
   char *out;
   char c;
 
@@ -556,8 +556,8 @@ _g_decode_uri (const char *uri)
   
   decoded->scheme = g_malloc (p - uri);
   out = decoded->scheme;
-  for (in = uri; in < p - 1; in++)
-    *out++ = g_ascii_tolower (*in);
+  for (inp = uri; inp < p - 1; inp++)
+    *out++ = g_ascii_tolower (*inp);
   *out = 0;
 
   hier_part_start = p;

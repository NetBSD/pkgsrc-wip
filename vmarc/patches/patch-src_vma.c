$NetBSD$

- ctype macros need unsigned char as argument.

--- src/vma.c.orig	2022-07-23 18:05:04.000000000 +0000
+++ src/vma.c
@@ -448,7 +448,7 @@ make_name( SUBFILE *sf )
         mode = s_name;
         while( *mode )
         {
-            *mode = tolower( *mode );
+            *mode = tolower( (unsigned char)*mode );
             mode++;
         }
     }
@@ -829,7 +829,7 @@ main( int argc, char *argv[] )
                     tok = fn;
                     while( tok && *tok )
                     {
-                        *tok = toupper( *tok );
+                        *tok = toupper( (unsigned char)*tok );
                         tok++;
                     }
                 }
@@ -839,7 +839,7 @@ main( int argc, char *argv[] )
                     tok = ft;
                     while( tok && *tok )
                     {
-                        *tok = toupper( *tok );
+                        *tok = toupper( (unsigned char)*tok );
                         tok++;
                     }
                 }
@@ -849,7 +849,7 @@ main( int argc, char *argv[] )
                     tok = fm;
                     while( tok && *tok )
                     {
-                        *tok = toupper( *tok );
+                        *tok = toupper( (unsigned char)*tok );
                         tok++;
                     }
                 }

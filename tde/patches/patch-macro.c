$NetBSD: patch-macro.c,v 1.1 2013/01/03 13:06:34 othyro Exp $

key_name is already defined in curses.h.

--- macro.c.orig	2006-08-28 06:22:00.000000000 +0000
+++ macro.c
@@ -539,7 +539,7 @@ int  i, j;
                   key = 256 | (j << 9);
                   for (i = 0; i < MAX_KEYS; ++i) {
                      if (macro[j][i] != NULL) {
-                        fprintf( fp, "%s %s", key_name( i | key, answer ),
+                        fprintf( fp, "%s %s", key_name( i | key ),
                                               func_str[PlayBack] );
                         write_macro( fp, macro[j][i], i | key );
                      }
@@ -674,7 +674,7 @@ char ch;
          if (key & _FUNCTION)
             fputs( func_str[func], file );
          else
-            fputs( key_name( key, str ), file );
+            fputs( key_name( key ), file );
          function = TRUE;
       }
    }
@@ -748,7 +748,7 @@ char buf[KEY_STR_MAX];
    while (twokey != NULL) {
       write_twokeymacro( file, twokey->left );
       if (twokey->macro != NULL) {
-         fprintf( file, "%s %s", key_name( twokey->key, buf ),
+         fprintf( file, "%s %s", key_name( twokey->key ),
                                  func_str[PlayBack] );
          write_macro( file, twokey->macro, twokey->key );
       }
@@ -756,51 +756,6 @@ char buf[KEY_STR_MAX];
    }
 }
 
-
-/*
- * Name:    key_name
- * Purpose: determine the string associated with a key
- * Author:  Jason Hood
- * Date:    August 21, 1998
- * Passed:  key:     key number to convert
- *          buffer:  place to store the string
- * Returns: buffer
- * Notes:   minimum buffer size should be KEY_STR_MAX characters (see config.h)
- *
- * 990428:  place ';' in quotes.
- *          recognize the viewer keys.
- * 990429:  write '"' correctly ("""").
- */
-char *key_name( long key, char *buffer )
-{
-int  twokey;
-int  j = 0;
-
-   twokey = PARENT_KEY( key );
-   if (twokey) {
-      j = strlen( key_name( twokey, buffer ) );
-      buffer[j++] = ' ';
-      key = CHILD_KEY( key );
-   }
-
-   if (key & _SHIFT) {
-      buffer[j++] = 's';
-      buffer[j++] = '+';
-   }
-   if (key & _CTRL) {
-      buffer[j++] = 'c';
-      buffer[j++] = '+';
-   }
-   if (key & _ALT) {
-      buffer[j++] = 'a';
-      buffer[j++] = '+';
-   }
-   strcpy( buffer+j, cfg_key[KEY( key )] );
-
-   return( buffer );
-}
-
-
 /*
  * Name:    clear_macros
  * Purpose: reset all macro buffers, pointers, functions.

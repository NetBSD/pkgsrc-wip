$NetBSD$

"dir" was allocated as arrary.

--- src/DOOM/wad.cpp.orig	2004-05-08 20:54:08.000000000 +0000
+++ src/DOOM/wad.cpp
@@ -1137,7 +1137,7 @@ bool wadList::Save ( const char *newName
             errors = true;
             fprintf ( stderr, "\nERROR: wadList::Save - Error writing directory." );
         }
-        delete dir;
+        delete [] dir;
 
         fseek ( tmpFile, 0, SEEK_SET );
         if ( fwrite ( &m_Header, sizeof ( m_Header ), 1, tmpFile ) != 1 ) {

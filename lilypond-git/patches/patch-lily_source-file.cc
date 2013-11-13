$NetBSD: patch-lily_source-file.cc,v 1.1 2013/11/13 07:26:35 thomasklausner Exp $

--- lily/source-file.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/source-file.cc
@@ -181,8 +182,8 @@ Source_file::file_line_column_string (ch
       int l, ch, col, offset;
       get_counts (context_str0, &l, &ch, &col, &offset);
 
-      return name_string () + ":" + to_string (l)
-             + ":" + to_string (col + 1);
+      return name_string () + ":" + ::to_string (l)
+             + ":" + ::to_string (col + 1);
     }
 }
 
@@ -196,8 +197,8 @@ Source_file::quote_input (char const *po
   get_counts (pos_str0, &l, &ch, &col, &offset);
   string line = line_string (pos_str0);
   string context = line.substr (0, offset)
-                   + to_string ('\n')
-                   + to_string (' ', col)
+                   + ::to_string ('\n')
+                   + ::to_string (' ', col)
                    + line.substr (offset, line.length () - offset);
   return context;
 }

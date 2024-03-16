$NetBSD$

cast chars to unsigned for ctype functions

--- src/reflex.cpp.orig	2024-03-16 22:12:32.810243725 +0000
+++ src/reflex.cpp
@@ -274,10 +274,10 @@ static const Reflex::Library library_tab
 ////////////////////////////////////////////////////////////////////////////////
 
 /// Convert to lower case
-inline int lower(int c)
+inline char char_tolower(char c)
   /// @returns lower case char
 {
-  return std::isalpha(c) ? (c | 0x20) : c;
+  return static_cast<char>(std::isalpha(static_cast<unsigned char>(c)) ? (c | 0x20) : c);
 }
 
 /// Add file extension if not present, modifies the string argument and returns a copy
@@ -778,7 +778,7 @@ bool Reflex::get_line()
       line.push_back(c);
   }
   linelen = line.length();
-  while (linelen > 0 && std::isspace(line.at(linelen - 1)))
+  while (linelen > 0 && std::isspace(static_cast<unsigned char>(line.at(linelen - 1))))
     --linelen;
   line.resize(linelen);
   if (in.eof() && line.empty())
@@ -828,7 +828,7 @@ bool Reflex::skip_comment(size_t& pos)
 /// Match case-insensitive string s while ignoring the rest of the line, return true if OK
 bool Reflex::is(const char *s)
 {
-  for (size_t pos = 0; pos < linelen && *s != '\0' && lower(line.at(pos)) == *s; ++pos, ++s)
+  for (size_t pos = 0; pos < linelen && *s != '\0' && char_tolower(line.at(pos)) == *s; ++pos, ++s)
     continue;
   return *s == '\0';
 }
@@ -837,9 +837,9 @@ bool Reflex::is(const char *s)
 bool Reflex::ins(const char *s)
 {
   size_t pos = 0;
-  while (pos < linelen && std::isspace(line.at(pos)))
+  while (pos < linelen && std::isspace(static_cast<unsigned char>(line.at(pos))))
     ++pos;
-  while (pos < linelen && *s != '\0' && lower(line.at(pos)) == *s)
+  while (pos < linelen && *s != '\0' && char_tolower(line.at(pos)) == *s)
   {
     ++pos;
     ++s;
@@ -852,17 +852,17 @@ bool Reflex::br(size_t pos, const char *
 {
   if (s != NULL)
   {
-    if (pos >= linelen || *s == '\0' || lower(line.at(pos)) != *s++)
+    if (pos >= linelen || *s == '\0' || char_tolower(line.at(pos)) != *s++)
       return false;
-    while (++pos < linelen && *s != '\0' && lower(line.at(pos)) == *s++)
+    while (++pos < linelen && *s != '\0' && char_tolower(line.at(pos)) == *s++)
       continue;
   }
-  while (pos < linelen && std::isspace(line.at(pos)))
+  while (pos < linelen && std::isspace(static_cast<unsigned char>(line.at(pos))))
     ++pos;
   if (pos >= linelen || line.at(pos) != '{')
     return false;
   ++pos;
-  while (pos < linelen && std::isspace(line.at(pos)))
+  while (pos < linelen && std::isspace(static_cast<unsigned char>(line.at(pos))))
     ++pos;
   if (pos >= linelen)
     return true;
@@ -872,9 +872,9 @@ bool Reflex::br(size_t pos, const char *
 /// Advance pos to match case-insensitive initial part of the string s followed by white space, return true if OK
 bool Reflex::as(size_t& pos, const char *s)
 {
-  if (pos >= linelen || *s == '\0' || lower(line.at(pos)) != *s++)
+  if (pos >= linelen || *s == '\0' || char_tolower(line.at(pos)) != *s++)
     return false;
-  while (++pos < linelen && *s != '\0' && lower(line.at(pos)) == *s++)
+  while (++pos < linelen && *s != '\0' && char_tolower(line.at(pos)) == *s++)
     continue;
   return ws(pos);
 }
@@ -882,9 +882,9 @@ bool Reflex::as(size_t& pos, const char 
 /// Advance pos over whitespace, returns true if whitespace was found
 bool Reflex::ws(size_t& pos)
 {
-  if (pos >= linelen || (pos > 0 && !std::isspace(line.at(pos))))
+  if (pos >= linelen || (pos > 0 && !std::isspace(static_cast<unsigned char>(line.at(pos)))))
     return false;
-  while (pos < linelen && std::isspace(line.at(pos)))
+  while (pos < linelen && std::isspace(static_cast<unsigned char>(line.at(pos))))
     ++pos;
   return true;
 }
@@ -903,7 +903,7 @@ bool Reflex::eq(size_t& pos)
 /// Advance pos to end of line while skipping whitespace, return true if end of line
 bool Reflex::nl(size_t& pos)
 {
-  while (pos < linelen && std::isspace(line.at(pos)))
+  while (pos < linelen && std::isspace(static_cast<unsigned char>(line.at(pos))))
     ++pos;
   return pos >= linelen;
 }
@@ -911,7 +911,7 @@ bool Reflex::nl(size_t& pos)
 /// Check if current line starts a block of code or a comment
 bool Reflex::is_code()
 {
-  return linelen > 0 && ((std::isspace(line.at(0)) && options["freespace"].empty()) || is("%{") || is("//") || is("/*"));
+  return linelen > 0 && ((std::isspace(static_cast<unsigned char>(line.at(0))) && options["freespace"].empty()) || is("%{") || is("//") || is("/*"));
 }
 
 /// Check if current line starts a block of %top code
@@ -941,12 +941,12 @@ bool Reflex::is_begin_code()
 /// Advance pos over name (letters, digits, ., -, _ or any non-ASCII character > U+007F), return name
 std::string Reflex::get_name(size_t& pos)
 {
-  if (pos >= linelen || (!std::isalnum(line.at(pos)) && line.at(pos) != '_' && (line.at(pos) & 0x80) != 0x80))
+  if (pos >= linelen || (!std::isalnum(static_cast<unsigned char>(line.at(pos))) && line.at(pos) != '_' && (line.at(pos) & 0x80) != 0x80))
     return "";
   size_t loc = pos++;
   while (pos < linelen)
   {
-    if (!std::isalnum(line.at(pos)) && line.at(pos) != '_' && line.at(pos) != '-' && line.at(pos) != '.' && (line.at(pos) & 0x80) != 0x80)
+    if (!std::isalnum(static_cast<unsigned char>(line.at(pos))) && line.at(pos) != '_' && line.at(pos) != '-' && line.at(pos) != '.' && (line.at(pos) & 0x80) != 0x80)
       break;
     ++pos;
   }
@@ -961,7 +961,7 @@ std::string Reflex::get_namespace(size_t
   {
     if (line.at(pos) == ':' && pos + 1 < linelen && line.at(pos + 1) == ':') // parse ::
       ++pos;
-    else if (!std::isalnum(line.at(pos)) && line.at(pos) != '_' && line.at(pos) != '-' && line.at(pos) != '.' && (line.at(pos) & 0x80) != 0x80)
+    else if (!std::isalnum(static_cast<unsigned char>(line.at(pos))) && line.at(pos) != '_' && line.at(pos) != '-' && line.at(pos) != '.' && (line.at(pos) & 0x80) != 0x80)
       break;
     ++pos;
   }
@@ -971,14 +971,14 @@ std::string Reflex::get_namespace(size_t
 /// Advance pos over option name (letters, digits, +/hyphen/underscore), return name
 std::string Reflex::get_option(size_t& pos)
 {
-  if (pos >= linelen || !std::isalnum(line.at(pos)))
+  if (pos >= linelen || !std::isalnum(static_cast<unsigned char>(line.at(pos))))
     return "";
   size_t loc = pos++;
   while (pos < linelen)
   {
     if (line.at(pos) == '-' || line.at(pos) == '+') // normalize - and + to _
       line[pos] = '_';
-    else if (!std::isalnum(line.at(pos)) && line.at(pos) != '_')
+    else if (!std::isalnum(static_cast<unsigned char>(line.at(pos))) && line.at(pos) != '_')
       break;
     ++pos;
   }
@@ -995,7 +995,7 @@ std::string Reflex::get_start(size_t& po
   {
     if (line.at(pos) == '-') // normalize - to _
       line[pos] = '_';
-    else if (!std::isalnum(line.at(pos)) && line.at(pos) != '_' && (line.at(pos) & 0x80) != 0x80)
+    else if (!std::isalnum(static_cast<unsigned char>(line.at(pos))) && line.at(pos) != '_' && (line.at(pos) & 0x80) != 0x80)
       break;
     ++pos;
   }
@@ -1047,7 +1047,7 @@ bool Reflex::get_pattern(size_t& pos, st
     if (fsp)
     {
       if (nsp < pos && (
-            (c == '{' && (pos + 1 == linelen || line.at(pos + 1) == '}' || std::isspace(line.at(pos + 1)))) ||
+            (c == '{' && (pos + 1 == linelen || line.at(pos + 1) == '}' || std::isspace(static_cast<unsigned char>(line.at(pos + 1))))) ||
             (c == '|' && pos + 1 == linelen) ||
             (c == '/' && pos + 1 < linelen && (line.at(pos + 1) == '/' || line.at(pos + 1) == '*'))))
       {
@@ -1055,7 +1055,7 @@ bool Reflex::get_pattern(size_t& pos, st
         break;
       }
     }
-    else if (std::isspace(c))
+    else if (std::isspace(static_cast<unsigned char>(c)))
     {
       break;
     }
@@ -1134,7 +1134,7 @@ bool Reflex::get_pattern(size_t& pos, st
         ++pos;
       }
     }
-    if (fsp && !std::isspace(c))
+    if (fsp && !std::isspace(static_cast<unsigned char>(c)))
       nsp = pos;
   }
   pattern.append(line.substr(loc, pos - loc));
@@ -1239,7 +1239,7 @@ std::string Reflex::get_code(size_t& pos
         }
         else
         {
-          if (blk == 0 && lev == 0 && linelen > 0 && (!std::isspace(line.at(0)) || !options["freespace"].empty()))
+          if (blk == 0 && lev == 0 && linelen > 0 && (!std::isspace(static_cast<unsigned char>(line.at(0))) || !options["freespace"].empty()))
             return code;
           code.append("\n").append(line);
         }
@@ -1312,8 +1312,8 @@ std::string Reflex::upper_name(const std
   std::string t;
   for (size_t i = 0; i < s.size(); ++i)
   {
-    if (std::isalnum(s.at(i)))
-      t.push_back(std::toupper(s.at(i)));
+    if (std::isalnum(static_cast<unsigned char>(s.at(i))))
+      t.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(s.at(i)))));
     else
       t.push_back('_');
   }
@@ -1337,11 +1337,11 @@ std::string Reflex::param_args(const std
     if (i <= from)
       i = to;
     while (--i > from)
-      if (!std::isspace(params.at(i)))
+      if (!std::isspace(static_cast<unsigned char>(params.at(i))))
         break;
     size_t j = i++;
     while (--i > from)
-      if (!std::isalnum(params.at(i)) && params.at(i) != '_')
+      if (!std::isalnum(static_cast<unsigned char>(params.at(i))) && params.at(i) != '_')
         break;
     if (!args.empty())
       args.append(", ");
@@ -1355,7 +1355,7 @@ std::string Reflex::param_args(const std
 bool Reflex::get_starts(size_t& pos, Starts& starts)
 {
   pos = 0;
-  if (linelen > 1 && line.at(0) == '<' && (std::isalpha(line.at(1)) || line.at(1) == '_' || line.at(1) == '*' || (line.at(1) & 0x80) == 0x80 || line.at(1) == '^') && line.find('>') != std::string::npos)
+  if (linelen > 1 && line.at(0) == '<' && (std::isalpha(static_cast<unsigned char>(line.at(1))) || line.at(1) == '_' || line.at(1) == '*' || (line.at(1) & 0x80) == 0x80 || line.at(1) == '^') && line.find('>') != std::string::npos)
   {
     do
     {

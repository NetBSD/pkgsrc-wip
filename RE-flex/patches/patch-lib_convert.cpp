$NetBSD$

cast chars to unsigned for ctype functions

--- lib/convert.cpp.orig	2024-03-16 22:11:51.956647653 +0000
+++ lib/convert.cpp
@@ -283,7 +283,7 @@ static int convert_hex(const char *patte
     size_t n = pos + 3;
     if (c == 'u')
       n += 2;
-    while (k < n && k < len && std::isxdigit(c = pattern[k++]))
+    while (k < n && k < len && std::isxdigit(static_cast<unsigned char>(c = pattern[k++])))
       *s++ = c;
     *s = '\0';
     --k;
@@ -337,7 +337,7 @@ static const std::string& expand(const s
 {
   // lookup {name} and expand without converting
   size_t k = pos++;
-  while (pos < len && (std::isalnum(pattern[pos]) || pattern[pos] == '_' || (pattern[pos] & 0x80) == 0x80))
+  while (pos < len && (std::isalnum(static_cast<unsigned char>(pattern[pos])) || pattern[pos] == '_' || (pattern[pos] & 0x80) == 0x80))
     ++pos;
   if (pos >= len || (pattern[pos] == '\\' ? pattern[pos + 1] != '}' : pattern[pos] != '}'))
     throw regex_error(regex_error::undefined_name, pattern, pos);
@@ -501,7 +501,7 @@ static void expand_list(const char *patt
     else if ((c & 0xC0) == 0xC0 && is_modified(mod, 'u'))
     {
       // Unicode normalization may need to combine a previous ASCII character with a Unicode combining character
-      if (loc < pos && std::isalpha(pattern[pos - 1]))
+      if (loc < pos && std::isalpha(static_cast<unsigned char>(pattern[pos - 1])))
         --pos;
       regex.append(&pattern[loc], pos - loc);
       const char *s = &pattern[pos];
@@ -551,7 +551,7 @@ static void insert_escape_class(const ch
     wc = Posix::range(name);
   if (wc == NULL)
     throw regex_error(regex_error::invalid_class, pattern, pos);
-  if (std::islower(c))
+  if (std::islower(static_cast<unsigned char>(c)))
   {
     if (wc[0] <= '\n' && wc[1] >= '\n' && (flags & convert_flag::notnewline))
     {
@@ -745,7 +745,7 @@ static int insert_escape(const char *pat
     pos = k;
     return -1;
   }
-  else if (std::isalpha(c))
+  else if (std::isalpha(static_cast<unsigned char>(c)))
   {
     const char *s = std::strchr(regex_abtnvfr, c);
     if (s == NULL)
@@ -1094,7 +1094,7 @@ static void convert_escape_char(const ch
   else if (std::strchr(regex_meta, c) == NULL)
   {
     char buf[3] = { '^', static_cast<char>(lowercase(c)), '\0' };
-    bool invert = std::isupper(c) != 0;
+    bool invert = std::isupper(static_cast<unsigned char>(c)) != 0;
     if (c == 'n' || (invert && strchr("DHLUWX", c) != NULL))
       nl = true;
     const char *name = buf + !invert;
@@ -1286,7 +1286,7 @@ static void convert_escape(const char *p
       throw regex_error(regex_error::invalid_escape, pattern, pos);
     if (wc == '\n')
       nl = true;
-    if (std::isalpha(wc) && is_modified(mod, 'i'))
+    if (std::isalpha(static_cast<unsigned char>(wc)) && is_modified(mod, 'i'))
     {
       // anycase: translate A to [Aa]
       regex.append(&pattern[loc], pos - loc - 1).push_back('[');
@@ -1335,7 +1335,7 @@ static void convert_escape(const char *p
         if (wc <= 0xFF)
         {
           // translate \u{X}, \u00XX (convert_flag::u4) and \x{X} to \xXX
-          if (std::isalpha(wc) && is_modified(mod, 'i'))
+          if (std::isalpha(static_cast<unsigned char>(wc)) && is_modified(mod, 'i'))
           {
             // anycase: translate A to [Aa]
             regex.append(&pattern[loc], pos - loc - 1).push_back('[');
@@ -1498,7 +1498,7 @@ std::string convert(const char *pattern,
       mods.push_back('m');
     size_t k = 2;
     bool invert = false;
-    while (k < len && (pattern[k] == '-' || std::isalpha(pattern[k])))
+    while (k < len && (pattern[k] == '-' || std::isalpha(static_cast<unsigned char>(pattern[k]))))
     {
       if (pattern[k] == '-')
       {
@@ -1711,7 +1711,7 @@ std::string convert(const char *pattern,
                 std::string mods, unmods;
                 size_t k = pos;
                 bool invert = false;
-                while (k < len && (pattern[k] == '-' || std::isalnum(pattern[k])))
+                while (k < len && (pattern[k] == '-' || std::isalnum(static_cast<unsigned char>(pattern[k]))))
                 {
                   if (pattern[k] == '-')
                   {
@@ -2006,7 +2006,7 @@ std::string convert(const char *pattern,
         }
         else
         {
-          if (macros != NULL && pos + 1 < len && (std::isalpha(pattern[pos + 1]) || pattern[pos + 1] == '_' || pattern[pos + 1] == '$' || (pattern[pos + 1] & 0x80) == 0x80))
+          if (macros != NULL && pos + 1 < len && (std::isalpha(static_cast<unsigned char>(pattern[pos + 1])) || pattern[pos + 1] == '_' || pattern[pos + 1] == '$' || (pattern[pos + 1] & 0x80) == 0x80))
           {
             // if macros are provided: lookup {name} and expand without converting
             regex.append(&pattern[loc], pos - loc);
@@ -2039,7 +2039,7 @@ std::string convert(const char *pattern,
             if (beg)
               throw regex_error(regex_error::empty_expression, pattern, pos);
             ++pos;
-            if (pos >= len || !std::isdigit(pattern[pos]))
+            if (pos >= len || !std::isdigit(static_cast<unsigned char>(pattern[pos])))
               throw regex_error(regex_error::invalid_repeat, pattern, pos);
             char *s;
             size_t n = static_cast<size_t>(std::strtoul(&pattern[pos], &s, 10));
@@ -2204,7 +2204,7 @@ std::string convert(const char *pattern,
         beg = false;
         break;
       default:
-        if (std::isalpha(pattern[pos]))
+        if (std::isalpha(static_cast<unsigned char>(pattern[pos])))
         {
           if (is_modified(mod, 'i'))
           {
@@ -2219,7 +2219,7 @@ std::string convert(const char *pattern,
         else if ((c & 0xC0) == 0xC0 && is_modified(mod, 'u'))
         {
           // Unicode normalization may need to combine a previous ASCII character with a Unicode combining character
-          if (loc < pos && std::isalpha(pattern[pos - 1]))
+          if (loc < pos && std::isalpha(static_cast<unsigned char>(pattern[pos - 1])))
             --pos;
           regex.append(&pattern[loc], pos - loc);
           const char *s = &pattern[pos];

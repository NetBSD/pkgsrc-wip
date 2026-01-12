$NetBSD$

Avoid ctype(3) undefined behaviours.

Shared upstream via:
<https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/>

--- src/cssparser.cc.orig	2026-01-06 16:25:07.230739234 +0000
+++ src/cssparser.cc
@@ -530,7 +530,7 @@ void CssParser::nextToken()
 
    while (true) {
       c = getChar();
-      if (isspace(c)) {                    // ignore whitespace
+      if (isspace((unsigned char)c)) {                    // ignore whitespace
          spaceSeparated = true;
       } else if (skipString(c, "/*")) {    // ignore comments
          do {
@@ -550,7 +550,7 @@ void CssParser::nextToken()
       c = getChar();
    }
 
-   if (isdigit(c)) {
+   if (isdigit((unsigned char)c)) {
       ttype = CSS_TK_DECINT;
       do {
          if (i < maxStrLen - 1) {
@@ -567,7 +567,7 @@ void CssParser::nextToken()
 
    if (c == '.') {
       c = getChar();
-      if (isdigit(c)) {
+      if (isdigit((unsigned char)c)) {
          ttype = CSS_TK_FLOAT;
          if (i < maxStrLen - 1)
             tval[i++] = '.';
@@ -576,7 +576,7 @@ void CssParser::nextToken()
                tval[i++] = c;
             /* else silently truncated */
             c = getChar();
-         } while (isdigit(c));
+         } while (isdigit((unsigned char)c));
 
          ungetChar();
          tval[i] = 0;
@@ -604,13 +604,13 @@ void CssParser::nextToken()
       c = getChar();
    }
 
-   if (isalpha(c) || c == '_' || c == '-') {
+   if (isalpha((unsigned char)c) || c == '_' || c == '-') {
       ttype = CSS_TK_SYMBOL;
 
       tval[0] = c;
       i = 1;
       c = getChar();
-      while (isalnum(c) || c == '_' || c == '-') {
+      while (isalnum((unsigned char)c) || c == '_' || c == '-') {
          if (i < maxStrLen - 1) {
             tval[i] = c;
             i++;
@@ -633,13 +633,13 @@ void CssParser::nextToken()
       while (c != EOF && c != c1) {
          if (c == '\\') {
             d = getChar();
-            if (isxdigit(d)) {
+            if (isxdigit((unsigned char)d)) {
                /* Read hex Unicode char. (Actually, strings are yet only 8
                 * bit.) */
                hexbuf[0] = d;
                j = 1;
                d = getChar();
-               while (j < 4 && isxdigit(d)) {
+               while (j < 4 && isxdigit((unsigned char)d)) {
                   hexbuf[j] = d;
                   j++;
                   d = getChar();
@@ -674,7 +674,7 @@ void CssParser::nextToken()
       tval[0] = c;
       i = 1;
       c = getChar();
-      while (isxdigit(c)) {
+      while (isxdigit((unsigned char)c)) {
          if (i < maxStrLen - 1) {
             tval[i] = c;
             i++;

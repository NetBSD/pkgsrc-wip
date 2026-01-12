$NetBSD$

Avoid ctype(3) undefined behaviours.

Shared upstream via:
<https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/>

--- src/html.cc.orig	2026-01-06 16:25:07.239433534 +0000
+++ src/html.cc
@@ -883,7 +883,7 @@ static const char *Html_parse_numeric_ch
    errno = 0;
 
    if (*s == 'x' || *s == 'X') {
-      if (isxdigit(*++s)) {
+      if (isxdigit((unsigned char)*++s)) {
          /* strtol with base 16 accepts leading "0x" - we don't */
          if (*s == '0' && s[1] == 'x') {
             s++;
@@ -892,7 +892,7 @@ static const char *Html_parse_numeric_ch
             codepoint = strtol(s, &s, 16);
          }
       }
-   } else if (isdigit(*s)) {
+   } else if (isdigit((unsigned char)*s)) {
       codepoint = strtol(s, &s, 10);
    }
    if (errno)
@@ -984,7 +984,7 @@ static const char *Html_parse_named_char
    char *s = tok;
    const char *ret = NULL;
 
-   while (*++s && (isalnum(*s) || strchr(":_.-", *s))) ;
+   while (*++s && (isalnum((unsigned char)*s) || strchr(":_.-", *s))) ;
    c = *s;
    *s = '\0';
    if (c != ';') {
@@ -1051,7 +1051,7 @@ static const char *Html_parse_entity(Dil
 
    if (*tok == '#') {
       ret = Html_parse_numeric_charref(html, tok+1, is_attr, entsize);
-   } else if (isalpha(*tok)) {
+   } else if (isalpha((unsigned char)*tok)) {
       ret = Html_parse_named_charref(html, tok, is_attr, entsize);
    } else if (prefs.show_extra_warnings &&
        (!(html->DocType == DT_HTML && html->DocTypeVersion >= 5.0f))) {
@@ -1249,11 +1249,11 @@ static void Html_process_word(DilloHtml 
       /* all this overhead is to catch white-space entities */
       Pword = a_Html_parse_entities(html, word, size);
       for (start = i = 0; Pword[i]; start = i)
-         if (isspace(Pword[i])) {
-            while (Pword[++i] && isspace(Pword[i])) ;
+         if (isspace((unsigned char)Pword[i])) {
+            while (Pword[++i] && isspace((unsigned char)Pword[i])) ;
             Html_process_space(html, Pword + start, i - start);
          } else {
-            while (Pword[++i] && !isspace(Pword[i])) ;
+            while (Pword[++i] && !isspace((unsigned char)Pword[i])) ;
             HT2TB(html)->addText(Pword + start, i - start, html->wordStyle ());
             html->pre_column += i - start;
             html->PreFirstChar = false;
@@ -1287,8 +1287,8 @@ static void Html_process_word(DilloHtml 
       for (start = i = 0; word2[i]; start = i) {
          int len;
 
-         if (isspace(word2[i])) {
-            while (word2[++i] && isspace(word2[i])) ;
+         if (isspace((unsigned char)word2[i])) {
+            while (word2[++i] && isspace((unsigned char)word2[i])) ;
             Html_process_space(html, word2 + start, i - start);
          } else if (!strncmp(word2+i, utf8_zero_width_space, 3)) {
             i += 3;
@@ -1300,7 +1300,7 @@ static void Html_process_word(DilloHtml 
          } else {
             do {
                i += len;
-            } while (word2[i] && !isspace(word2[i]) &&
+            } while (word2[i] && !isspace((unsigned char)word2[i]) &&
                      strncmp(word2+i, utf8_zero_width_space, 3) &&
                      (!a_Utf8_ideographic(word2+i, beyond_word2, &len)));
             HT2TB(html)->addText(word2 + start, i - start, html->wordStyle ());
@@ -1324,7 +1324,7 @@ static bool Html_match_tag(const char *t
          return false;
    }
    /* The test for '/' is for xml compatibility: "empty/>" will be matched. */
-   if (i < tagsize && (isspace(tag[i]) || tag[i] == '>' || tag[i] == '/'))
+   if (i < tagsize && (isspace((unsigned char)tag[i]) || tag[i] == '>' || tag[i] == '/'))
       return true;
    return false;
 }
@@ -1441,7 +1441,7 @@ CssLength a_Html_parse_length (DilloHtml
       l = CSS_CREATE_LENGTH(0.0, CSS_LENGTH_TYPE_AUTO);
    else {
       /* allow only whitespaces */
-      if (*end && !isspace (*end)) {
+      if (*end && !isspace ((unsigned char)*end)) {
          BUG_MSG("Garbage after length: '%s'.", attr);
          l = CSS_CREATE_LENGTH(0.0, CSS_LENGTH_TYPE_AUTO);
       }
@@ -1487,10 +1487,10 @@ static int
       int i;
 
       for (i = 0; val[i]; ++i)
-         if (!d_isascii(val[i]) || !(isalnum(val[i]) || strchr(":_.-", val[i])))
+         if (!d_isascii(val[i]) || !(isalnum((unsigned char)val[i]) || strchr(":_.-", val[i])))
             break;
 
-      if (val[i] || !(d_isascii(val[0]) && isalpha(val[0])))
+      if (val[i] || !(d_isascii(val[0]) && isalpha((unsigned char)val[0])))
          BUG_MSG("%s attribute value \"%s\" is not of the form "
                  "'[A-Za-z][A-Za-z0-9:_.-]*'.", attrname, val);
 
@@ -1537,8 +1537,8 @@ static void Html_parse_doctype(DilloHtml
    /* Tag sanitization: Collapse whitespace between tokens
     * and replace '\n' and '\r' with ' ' inside quoted strings. */
    for (i = 0, p = ntag; *p; ++p) {
-      if (isspace(*p)) {
-         for (ntag[i++] = ' '; isspace(p[1]); ++p) ;
+      if (isspace((unsigned char)*p)) {
+         for (ntag[i++] = ' '; isspace((unsigned char)p[1]); ++p) ;
       } else if ((quote = *p) == '"' || *p == '\'') {
          for (ntag[i++] = *p++; (ntag[i] = *p) && ntag[i++] != quote; ++p) {
             if (*p == '\n' || *p == '\r')
@@ -2376,7 +2376,7 @@ misc::SimpleVector<int> *Html_read_coord
          break;
       coords->increase();
       coords->set(coords->size() - 1, coord);
-      while (isspace(*newtail))
+      while (isspace((unsigned char)*newtail))
          newtail++;
       if (!*newtail)
          break;
@@ -4178,7 +4178,7 @@ static const char *Html_get_attr2(DilloH
    for (i = 1; i < tagsize; ++i) {
       switch (state) {
       case SEEK_ATTR_START:
-         if (isspace(tag[i]))
+         if (isspace((unsigned char)tag[i]))
             state = SEEK_TOKEN_START;
          else if (tag[i] == '=')
             state = SEEK_VALUE_START;
@@ -4186,7 +4186,7 @@ static const char *Html_get_attr2(DilloH
 
       case MATCH_ATTR_NAME:
          if (!attrname[attr_pos] &&
-             (tag[i] == '=' || isspace(tag[i]) || tag[i] == '>')) {
+             (tag[i] == '=' || isspace((unsigned char)tag[i]) || tag[i] == '>')) {
             Found = 1;
             state = SEEK_TOKEN_START;
             --i;
@@ -4202,14 +4202,14 @@ static const char *Html_get_attr2(DilloH
       case SEEK_TOKEN_START:
          if (tag[i] == '=') {
             state = SEEK_VALUE_START;
-         } else if (!isspace(tag[i])) {
+         } else if (!isspace((unsigned char)tag[i])) {
             attr_pos = 0;
             state = (Found) ? FINISHED : MATCH_ATTR_NAME;
             --i;
          }
          break;
       case SEEK_VALUE_START:
-         if (!isspace(tag[i])) {
+         if (!isspace((unsigned char)tag[i])) {
             delimiter = (tag[i] == '"' || tag[i] == '\'') ? tag[i] : ' ';
             i -= (delimiter == ' ');
             state = (Found) ? GET_VALUE : SKIP_VALUE;
@@ -4217,11 +4217,11 @@ static const char *Html_get_attr2(DilloH
          break;
 
       case SKIP_VALUE:
-         if ((delimiter == ' ' && isspace(tag[i])) || tag[i] == delimiter)
+         if ((delimiter == ' ' && isspace((unsigned char)tag[i])) || tag[i] == delimiter)
             state = SEEK_TOKEN_START;
          break;
       case GET_VALUE:
-         if ((delimiter == ' ' && (isspace(tag[i]) || tag[i] == '>')) ||
+         if ((delimiter == ' ' && (isspace((unsigned char)tag[i]) || tag[i] == '>')) ||
              tag[i] == delimiter) {
             state = FINISHED;
          } else if (tag[i] == '&' &&
@@ -4252,10 +4252,10 @@ static const char *Html_get_attr2(DilloH
    }
 
    if (tag_parsing_flags & HTML_LeftTrim)
-      while (isspace(Buf->str[0]))
+      while (isspace((unsigned char)Buf->str[0]))
          dStr_erase(Buf, 0, 1);
    if (tag_parsing_flags & HTML_RightTrim)
-      while (Buf->len && isspace(Buf->str[Buf->len - 1]))
+      while (Buf->len && isspace((unsigned char)Buf->str[Buf->len - 1]))
          dStr_truncate(Buf, Buf->len - 1);
 
    return (Found) ? Buf->str : NULL;
@@ -4349,14 +4349,14 @@ static int Html_write_raw(DilloHtml *htm
             break;
       }
 
-      if (isspace(buf[buf_index])) {
+      if (isspace((unsigned char)buf[buf_index])) {
          /* whitespace: group all available whitespace */
-         while (++buf_index < bufsize && isspace(buf[buf_index])) ;
+         while (++buf_index < bufsize && isspace((unsigned char)buf[buf_index])) ;
          Html_process_space(html, buf + token_start, buf_index - token_start);
          token_start = buf_index;
 
       } else if (buf[buf_index] == '<' && (ch = buf[buf_index + 1]) &&
-                 (isalpha(ch) || strchr("/!?", ch)) ) {
+                 (isalpha((unsigned char)ch) || strchr("/!?", ch)) ) {
          /* Tag */
          if (buf_index + 3 < bufsize && !strncmp(buf + buf_index, "<!--", 4)) {
             /* Comment: search for close of comment, skipping over
@@ -4422,7 +4422,7 @@ static int Html_write_raw(DilloHtml *htm
          while (++buf_index < bufsize) {
             buf_index += strcspn(buf + buf_index, " <\n\r\t\f\v");
             if (buf[buf_index] == '<' && (ch = buf[buf_index + 1]) &&
-                !isalpha(ch) && !strchr("/!?", ch))
+                !isalpha((unsigned char)ch) && !strchr("/!?", ch))
                continue;
             break;
          }

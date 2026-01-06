$NetBSD$

Avoid ctype(3) undefined behaviours.

--- dw/textblock.cc.orig	2026-01-06 16:25:07.218295539 +0000
+++ dw/textblock.cc
@@ -1238,14 +1238,14 @@ void Textblock::drawText(core::View *vie
                bool initial_seen = false;
 
                for (int i = 0; i < start; i++)
-                  if (!ispunct(text[i]))
+                  if (!ispunct((unsigned char)text[i]))
                      initial_seen = true;
                if (initial_seen)
                   break;
 
                int after = 0;
                text += start;
-               while (ispunct(text[after]))
+               while (ispunct((unsigned char)text[after]))
                   after++;
                if (text[after])
                   after = layout->nextGlyph(text, after);
@@ -1931,7 +1931,7 @@ int Textblock::textWidth(const char *tex
                bool initial_seen = false;
 
                for (int i = 0; i < start; i++)
-                  if (!ispunct(text[i]))
+                  if (!ispunct((unsigned char)text[i]))
                      initial_seen = true;
                if (initial_seen) {
                   ret = layout->textWidth(style->font, text+start, len);
@@ -1939,7 +1939,7 @@ int Textblock::textWidth(const char *tex
                   int after = 0;
 
                   text += start;
-                  while (ispunct(text[after]))
+                  while (ispunct((unsigned char)text[after]))
                      after++;
                   if (text[after])
                      after = layout->nextGlyph(text, after);

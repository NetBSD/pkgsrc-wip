$NetBSD$

Avoid ctype(3) undefined behaviours.

--- src/keys.cc.orig	2026-01-06 16:25:07.236435264 +0000
+++ src/keys.cc
@@ -203,7 +203,7 @@ KeysCommand_t Keys::getKeyCmd()
    KeyBinding_t keyNode;
 
    keyNode.modifier = Fl::event_state() & (FL_SHIFT | FL_CTRL |FL_ALT|FL_META);
-   if (iscntrl(Fl::event_text()[0])) {
+   if (iscntrl((unsigned char)Fl::event_text()[0])) {
       keyNode.key = Fl::event_key();
    } else {
       const char *beyond = Fl::event_text() + Fl::event_length();
@@ -326,7 +326,7 @@ void Keys::parseKey(char *key, char *com
    }
 
    // Skip space
-   for (  ; isspace(*key); ++key) ;
+   for (  ; isspace((unsigned char)*key); ++key) ;
    // Get modifiers
    while(*key == '<' && (p = strchr(key, '>'))) {
       ++key;

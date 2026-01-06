$NetBSD$

Avoid ctype(3) undefined behaviours.

--- dw/findtext.hh.orig	2026-01-06 16:25:07.212143829 +0000
+++ dw/findtext.hh
@@ -66,8 +66,8 @@ private:
    bool search0 (bool backwards, bool firstTrial);
 
    inline static bool charsEqual (char c1, char c2, bool caseSens)
-   { return caseSens ? c1 == c2 : tolower (c1) == tolower (c2) ||
-      (isspace (c1) && isspace (c2)); }
+   { return caseSens ? c1 == c2 : tolower ((unsigned char)c1) == tolower ((unsigned char)c2) ||
+      (isspace ((unsigned char)c1) && isspace ((unsigned char)c2)); }
 
 public:
    FindtextState ();

$NetBSD$

Assume the assets directory is at the same level. This is pkgsrc-specific.

--- src/Skeleton.elm.orig	2025-03-08 08:17:17.920123429 +0000
+++ src/Skeleton.elm
@@ -57,7 +57,7 @@ viewLogo =
     , style "display"         "flex"
     , style "align-items"     "center"
     ]
-    [ img [ alt "logo", src "../assets/dmarcaroni.logo.svg", width 300] [ ]
+    [ img [ alt "logo", src "./assets/dmarcaroni.logo.svg", width 300] [ ]
     ]
 
 viewFooter : Html msg

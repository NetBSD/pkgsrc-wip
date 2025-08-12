$NetBSD$

--- modules/javafx.graphics/src/main/java/com/sun/javafx/font/LogicalFont.java.orig	2024-10-21 13:21:27.486740460 +0000
+++ modules/javafx.graphics/src/main/java/com/sun/javafx/font/LogicalFont.java
@@ -171,7 +171,7 @@ public class LogicalFont implements Comp
             styleName = STYLE_BOLD_ITALIC;
         }
         fullName = familyName + " " + styleName;
-        if (PrismFontFactory.isLinux) {
+        if (PrismFontFactory.isLinux || PrismFontFactory.isNetBSD) {
             FontConfigManager.FcCompFont fcCompFont =
                 FontConfigManager.getFontConfigFont(family, bold, italic);
             physicalFullName = fcCompFont.firstFont.fullName;

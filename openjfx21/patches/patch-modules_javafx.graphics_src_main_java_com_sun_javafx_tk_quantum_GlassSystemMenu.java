$NetBSD$

--- modules/javafx.graphics/src/main/java/com/sun/javafx/tk/quantum/GlassSystemMenu.java.orig	2024-10-21 13:26:25.192842112 +0000
+++ modules/javafx.graphics/src/main/java/com/sun/javafx/tk/quantum/GlassSystemMenu.java
@@ -316,13 +316,13 @@ class GlassSystemMenu implements TKSyste
         } else if (accelerator instanceof KeyCodeCombination) {
             KeyCodeCombination kcc  = (KeyCodeCombination)accelerator;
             KeyCode            code = kcc.getCode();
-            assert PlatformUtil.isMac() || PlatformUtil.isLinux();
+            assert PlatformUtil.isMac() || PlatformUtil.isLinux() || PlatformUtil.isNetBSD();
             int modifier = glassModifiers(kcc);
             if (PlatformUtil.isMac()) {
                 int finalCode = code.isLetterKey() ? code.getChar().toUpperCase().charAt(0)
                         : code.getCode();
                 glassSubMenuItem.setShortcut(finalCode, modifier);
-            } else if (PlatformUtil.isLinux()) {
+            } else if (PlatformUtil.isLinux() || PlatformUtil.isNetBSD()) {
                 String lower = code.getChar().toLowerCase();
                 if ((modifier & KeyEvent.MODIFIER_CONTROL) != 0) {
                     glassSubMenuItem.setShortcut(lower.charAt(0), modifier);
@@ -351,14 +351,14 @@ class GlassSystemMenu implements TKSyste
             ret += KeyEvent.MODIFIER_ALT;
         }
         if (kcc.getShortcut() == KeyCombination.ModifierValue.DOWN) {
-            if (PlatformUtil.isLinux()) {
+            if (PlatformUtil.isLinux() || PlatformUtil.isNetBSD()) {
                 ret += KeyEvent.MODIFIER_CONTROL;
             } else if (PlatformUtil.isMac()) {
                 ret += KeyEvent.MODIFIER_COMMAND;
             }
         }
         if (kcc.getMeta() == KeyCombination.ModifierValue.DOWN) {
-            if (PlatformUtil.isLinux()) {
+            if (PlatformUtil.isLinux() || PlatformUtil.isNetBSD()) {
                 ret += KeyEvent.MODIFIER_WINDOWS;   // RT-19326 - Linux shortcut support
             } else if (PlatformUtil.isMac()) {
                 ret += KeyEvent.MODIFIER_COMMAND;

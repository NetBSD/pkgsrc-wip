$NetBSD$

--- modules/javafx.controls/src/main/java/com/sun/javafx/scene/control/behavior/TextInputControlBehavior.java.orig	2024-10-21 13:19:58.353820234 +0000
+++ modules/javafx.controls/src/main/java/com/sun/javafx/scene/control/behavior/TextInputControlBehavior.java
@@ -56,6 +56,7 @@ import java.text.Bidi;
 import java.util.function.Predicate;
 
 import static com.sun.javafx.PlatformUtil.isLinux;
+import static com.sun.javafx.PlatformUtil.isNetBSD;
 import static com.sun.javafx.PlatformUtil.isMac;
 import static com.sun.javafx.PlatformUtil.isWindows;
 import static com.sun.javafx.scene.control.inputmap.KeyBinding.OptionalBoolean;
@@ -552,7 +553,7 @@ public abstract class TextInputControlBe
 
     public void selectNextWord() {
         TextInputControl textInputControl = getNode();
-        if (isMac() || isLinux()) {
+        if (isMac() || isLinux() || isNetBSD()) {
             textInputControl.selectEndOfNextWord();
         } else {
             textInputControl.selectNextWord();
@@ -601,7 +602,7 @@ public abstract class TextInputControlBe
 
     protected void nextWord() {
         TextInputControl textInputControl = getNode();
-        if (isMac() || isLinux()) {
+        if (isMac() || isLinux() || isNetBSD()) {
             textInputControl.endOfNextWord();
         } else {
             textInputControl.nextWord();

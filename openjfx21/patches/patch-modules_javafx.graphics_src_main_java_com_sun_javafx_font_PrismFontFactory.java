$NetBSD$

--- modules/javafx.graphics/src/main/java/com/sun/javafx/font/PrismFontFactory.java.orig	2024-10-21 13:24:59.712095825 +0000
+++ modules/javafx.graphics/src/main/java/com/sun/javafx/font/PrismFontFactory.java
@@ -51,6 +51,7 @@ public abstract class PrismFontFactory i
     public static final boolean debugFonts;
     public static final boolean isWindows;
     public static final boolean isLinux;
+    public static final boolean isNetBSD;
     public static final boolean isMacOSX;
     public static final boolean isIOS;
     public static final boolean isAndroid;
@@ -86,6 +87,7 @@ public abstract class PrismFontFactory i
         isWindows = PlatformUtil.isWindows();
         isMacOSX  = PlatformUtil.isMac();
         isLinux   = PlatformUtil.isLinux();
+        isNetBSD  = PlatformUtil.isNetBSD();
         isIOS     = PlatformUtil.isIOS();
         isAndroid = PlatformUtil.isAndroid();
         isEmbedded = PlatformUtil.isEmbedded();
@@ -164,7 +166,7 @@ public abstract class PrismFontFactory i
     private static String getNativeFactoryName() {
         if (isWindows) return DW_FACTORY;
         if (isMacOSX || isIOS) return CT_FACTORY;
-        if (isLinux || isAndroid) return FT_FACTORY;
+        if (isLinux || isAndroid || isNetBSD) return FT_FACTORY;
         return null;
     }
 
@@ -884,7 +886,7 @@ public abstract class PrismFontFactory i
                         break;
                     }
                 }
-                if (fontResource == null && isLinux) {
+                if (fontResource == null && (isLinux || isNetBSD)) {
                     String path = FontConfigManager.getDefaultFontPath();
                     if (path != null) {
                         fontResource = createFontResource(jreDefaultFontLC,
@@ -1724,7 +1726,7 @@ public abstract class PrismFontFactory i
                                 fontToFamilyNameMap,
                                 familyToFontListMap);
                 }
-            } else if (isLinux) {
+            } else if (isLinux || isNetBSD) {
                 FontConfigManager.populateMaps(tmpFontToFileMap,
                                                fontToFamilyNameMap,
                                                familyToFontListMap,

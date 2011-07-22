$NetBSD: patch-j2se_src_share_classes_sun_awt_FontConfiguration.java,v 1.1 2011/07/22 14:10:18 ftigeot Exp $

--- j2se/src/share/classes/sun/awt/FontConfiguration.java.orig	2011-07-22 12:15:36 +0000
+++ j2se/src/share/classes/sun/awt/FontConfiguration.java
@@ -1291,7 +1291,8 @@ public abstract class FontConfiguration 
 				   + "<filename." 
 				   + getString(table_componentFontNameIDs[ii])
                                    + "> entry is missing!!!");
-                if (!osName.contains("Linux") && !osName.contains("BSD") && !osName.contains("Darwin")) {
+                if (!osName.contains("Linux") && !osName.contains("BSD")
+			&& !osName.contains("Darwin") && !osName.contains("DragonFly")) {
 		    errors++;
 		}
             }

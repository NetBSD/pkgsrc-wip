$NetBSD$

--- components/neterror/resources/neterror.js.orig	2016-06-24 01:02:18.000000000 +0000
+++ components/neterror/resources/neterror.js
@@ -147,7 +147,7 @@ function setUpCachedButton(buttonStrings
 }
 
 var primaryControlOnLeft = true;
-<if expr="is_macosx or is_ios or is_linux or is_android">
+<if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 </if>
 

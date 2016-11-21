$NetBSD$

Fix includes.
auto_ptr is deprecated.

--- src/player.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/player.cpp
@@ -9,7 +9,7 @@
 #include "inventory.h"
 #include "options.h"
 #include <sstream>
-#include <stdlib.h>
+#include <cstdlib>
 #include "weather.h"
 #include "item.h"
 #include "material.h"
@@ -28,8 +28,8 @@
 #include "sounds.h"
 
 //Used for e^(x) functions
-#include <stdio.h>
-#include <math.h>
+#include <cstdio>
+#include <cmath>
 
 #include <ctime>
 #include <algorithm>
@@ -9788,7 +9788,7 @@ void player::pick_style() // Style selec
 
     uimenu kmenu;
     kmenu.text = _("Select a style (press ? for style info)");
-    std::auto_ptr<ma_style_callback> ma_style_info(new ma_style_callback());
+    std::unique_ptr<ma_style_callback> ma_style_info(new ma_style_callback());
     kmenu.callback = ma_style_info.get();
     kmenu.addentry( 0, true, 'c', _("Cancel") );
     if (keep_hands_free) {

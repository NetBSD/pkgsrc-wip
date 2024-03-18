$NetBSD$

Add math.h for M_PI.

--- gameSource/sound/SoundEffectsBank.cpp.orig	2024-03-18 13:22:28.191496060 +0000
+++ gameSource/sound/SoundEffectsBank.cpp
@@ -5,6 +5,7 @@
  * Created.
  */
 
+#include <math.h>
 
 #include "SoundEffectsBank.h"
 

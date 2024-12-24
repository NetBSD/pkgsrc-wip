$NetBSD$

--- src/AudioWaveformer.cpp.orig	2024-12-24 10:42:51.855734280 +0000
+++ src/AudioWaveformer.cpp
@@ -10,6 +10,7 @@
 //
 // SPDX-License-Identifier: LGPL-3.0-or-later
 
+#include <cmath>
 #include "AudioWaveformer.h"
 
 

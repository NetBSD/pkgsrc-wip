$NetBSD: patch-engine_namefield.cpp,v 1.1 2013/01/01 01:15:36 othyro Exp $

Needs a few SDL functions.

--- engine/namefield.cpp.orig	2005-03-31 01:02:41.000000000 +0000
+++ engine/namefield.cpp
@@ -29,6 +29,7 @@
 	The full text of the license can be found in lgpl.txt
 */
 
+#include <SDL/SDL.h>
 #include "namefield.h"
 #include "../util/glstring.h"
 #include "../../grinliz/glutil.h"

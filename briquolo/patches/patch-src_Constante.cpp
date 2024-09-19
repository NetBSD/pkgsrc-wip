$NetBSD: patch-src_Constante.cpp,v 1.1 2012/06/13 22:54:58 othyro Exp $

Needs getenv.

--- src/Constante.cpp.orig	2008-03-22 09:40:33.000000000 +0000
+++ src/Constante.cpp
@@ -21,6 +21,8 @@
  *****************************************************************************/
 #include "Constante.h"
 
+#include <stdlib.h>
+
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #else

$NetBSD: patch-src_MOGL_MOGL__Objet.cpp,v 1.1 2012/06/13 22:54:58 othyro Exp $

Needs free and malloc.

--- src/MOGL/MOGL_Objet.cpp.orig	2006-03-07 20:31:24.000000000 +0000
+++ src/MOGL/MOGL_Objet.cpp
@@ -21,6 +21,8 @@
  *****************************************************************************/
 #include "MOGL_Objet.h"
 
+#include <stdlib.h>
+
 //MOGL_Objet::MOGL_Objet(): MOGL_ObjetAbstrait(), MOGL_ElementArbre()
 MOGL_Objet::MOGL_Objet(): MOGL_Noeud(), _ModifieTriangle(true), _ModifieStrip(true),
 //                          _AbonnementTrianglesUnique(0), _AbonnementStripsUnique(0),

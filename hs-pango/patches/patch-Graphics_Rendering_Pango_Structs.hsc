$NetBSD: patch-Graphics_Rendering_Pango_Structs.hsc,v 1.1.1.1 2011/07/12 10:18:38 phonohawk Exp $

% pkg-config --cflags glib-2.0
-I/usr/pkg/include/glib/glib-2.0 -I/usr/pkg/lib/glib-2.0/include

% ls /usr/pkg/include/glib/glib-2.0/glib.h
/usr/pkg/include/glib/glib-2.0/glib.h

--- Graphics/Rendering/Pango/Structs.hsc.orig	2010-11-07 14:59:25.000000000 +0000
+++ Graphics/Rendering/Pango/Structs.hsc
@@ -22,7 +22,7 @@
 -- #hide
 
 #include "hspango.h"
-#include <glib-2.0/glib.h>
+#include <glib.h>
 #include "template-hsc-gtk2hs.h"
 
 -- |

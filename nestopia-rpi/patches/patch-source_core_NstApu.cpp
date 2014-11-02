$NetBSD: patch-source_core_NstApu.cpp,v 1.1 2014/11/02 08:36:13 nsloss Exp $

Allow faster speed settings.
--- source/core/NstApu.cpp.orig	2008-06-07 13:28:16.000000000 +0000
+++ source/core/NstApu.cpp
@@ -363,7 +363,7 @@ namespace Nes
 			if (settings.speed == speed)
 				return RESULT_NOP;
 
-			if ((speed > 0 && speed < 30) || speed > 240)
+			if ((speed > 0 && speed < 30) || speed > 600)
 				return RESULT_ERR_UNSUPPORTED;
 
 			settings.speed = speed;

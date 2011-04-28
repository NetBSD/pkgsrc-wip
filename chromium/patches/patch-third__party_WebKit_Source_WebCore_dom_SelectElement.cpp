$NetBSD: patch-third__party_WebKit_Source_WebCore_dom_SelectElement.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/dom/SelectElement.cpp.orig	2011-04-13 08:12:19.000000000 +0000
+++ third_party/WebKit/Source/WebCore/dom/SelectElement.cpp
@@ -54,7 +54,7 @@
 #if PLATFORM(MAC) || (PLATFORM(CHROMIUM) && OS(DARWIN))
 #define ARROW_KEYS_POP_MENU 1
 #define SPACE_OR_RETURN_POP_MENU 0
-#elif PLATFORM(GTK) || (PLATFORM(CHROMIUM) && (OS(LINUX) || OS(FREEBSD)))
+#elif PLATFORM(GTK) || (PLATFORM(CHROMIUM) && (OS(LINUX) || OS(BSD)))
 #define ARROW_KEYS_POP_MENU 0
 #define SPACE_OR_RETURN_POP_MENU 1
 #else

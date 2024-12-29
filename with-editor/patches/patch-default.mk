$NetBSD$

work around

--- default.mk.orig	2024-12-30 04:31:36.943965754 +0900
+++ default.mk	2024-12-30 04:28:28.529903285 +0900
@@ -26,6 +26,7 @@ ORG_LOAD_PATH  = -L ../../org/lisp
 endif
 
 INSTALL_INFO     ?= $(shell command -v ginstall-info || printf install-info)
+INSTALL_INFO	= install-info
 MAKEINFO         ?= makeinfo
 MANUAL_HTML_ARGS ?= --css-ref /assets/page.css
 

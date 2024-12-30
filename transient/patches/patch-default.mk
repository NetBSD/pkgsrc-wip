$NetBSD$

work around

--- default.mk.orig	2024-12-09 07:27:38.000000000 +0900
+++ default.mk	2024-12-30 11:31:37.815417969 +0900
@@ -20,6 +20,7 @@ EMACS_ARGS ?= --eval "(progn \
   (put 'when-let 'byte-obsolete-info nil))"
 
 LOAD_PATH  ?= $(addprefix -L ../../,$(DEPS))
+LOAD_PATH  += -L @@PREFIX@@/share/emacs/site-lisp/compat
 LOAD_PATH  += -L .
 
 ifndef ORG_LOAD_PATH
@@ -27,6 +28,7 @@ ORG_LOAD_PATH  = -L ../../org/lisp
 endif
 
 INSTALL_INFO     ?= $(shell command -v ginstall-info || printf install-info)
+INSTALL_INFO	= install-info
 MAKEINFO         ?= makeinfo
 MANUAL_HTML_ARGS ?= --css-ref /assets/page.css
 

$NetBSD$

work around
 
--- default.mk.orig	2024-12-01 23:19:07.000000000 +0900
+++ default.mk	2024-12-30 12:24:32.887985629 +0900
@@ -19,6 +19,7 @@ EMACS_ARGS ?=
 EMACS_ARGS += --eval '(setq with-editor-emacsclient-executable nil)'
 
 LOAD_PATH  ?= $(addprefix -L ../../,$(DEPS))
+LOAD_PATH  += -L  @@PREFIX@@/share/emacs/site-lisp/compat
 LOAD_PATH  += -L .
 
 ifndef ORG_LOAD_PATH
@@ -26,6 +27,7 @@ ORG_LOAD_PATH  = -L ../../org/lisp
 endif
 
 INSTALL_INFO     ?= $(shell command -v ginstall-info || printf install-info)
+INSTALL_INFO	= install-info
 MAKEINFO         ?= makeinfo
 MANUAL_HTML_ARGS ?= --css-ref /assets/page.css
 

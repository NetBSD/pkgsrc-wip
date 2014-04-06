$NetBSD: patch-common.mk,v 1.2 2014/04/06 13:33:55 rhialto Exp $

Add support for NetBSD.
Make $(prefix) overridable.

--- common.mk.orig	2014-03-25 19:40:59.000000000 +0000
+++ common.mk
@@ -43,6 +43,14 @@ cxx = $(CXX)
 ar = $(AR)
 make = gmake
 
+else ifneq ($(findstring NetBSD,$(uname)),)
+
+os = netbsd
+cc = $(CC)
+cxx = $(CXX)
+ar = $(AR)
+make = gmake
+
 else ifneq ($(findstring OpenBSD,$(uname)),)
 
 os = openbsd
@@ -64,5 +72,5 @@ debug := 0
 devel := 0
 optimize := 1
 noflags := 0
-prefix := /usr
+prefix ?= /usr
 docdir := $(prefix)/share/doc/fs-uae

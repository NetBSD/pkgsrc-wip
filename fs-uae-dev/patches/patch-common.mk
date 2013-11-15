$NetBSD: patch-common.mk,v 1.1 2013/11/15 12:26:23 rhialto Exp $

Add support for NetBSD.

--- common.mk.orig	2013-10-23 17:58:00.000000000 +0000
+++ common.mk
@@ -35,6 +35,14 @@ cxx = $(CXX)
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
@@ -56,5 +64,5 @@ debug := 0
 devel := 0
 optimize := 1
 noflags := 0
-prefix := /usr
+prefix ?= /usr
 docdir := $(prefix)/share/doc/fs-uae

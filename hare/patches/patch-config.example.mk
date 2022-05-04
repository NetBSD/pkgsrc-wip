$NetBSD$

Allow configuration vars to be overridden
--- config.example.mk.orig	2022-05-03 19:56:11.565203456 -0700
+++ config.example.mk	2022-05-03 19:56:36.752923296 -0700
@@ -1,31 +1,31 @@
 ## Install configuration
 
-PREFIX = /usr
-BINDIR = $(PREFIX)/bin
-MANDIR = $(PREFIX)/share/man
-SRCDIR = $(PREFIX)/src
+PREFIX ?= /usr
+BINDIR ?= $(PREFIX)/bin
+MANDIR ?= $(PREFIX)/share/man
+SRCDIR ?= $(PREFIX)/src
 
 # Where to install the stdlib tree
-STDLIB = $(SRCDIR)/hare/stdlib
+STDLIB ?= $(SRCDIR)/hare/stdlib
 
 # Default HAREPATH
-LOCALSRCDIR = /usr/local/src/hare
-HAREPATH = $(LOCALSRCDIR)/stdlib:$(LOCALSRCDIR)/third-party:$(SRCDIR)/hare/stdlib:$(SRCDIR)/hare/third-party
+LOCALSRCDIR ?= /usr/local/src/hare
+HAREPATH ?= $(LOCALSRCDIR)/stdlib:$(LOCALSRCDIR)/third-party:$(SRCDIR)/hare/stdlib:$(SRCDIR)/hare/third-party
 
 ## Build configuration
 
 # Platform to build for
-PLATFORM = linux
-ARCH = x86_64
+PLATFORM ?= linux
+ARCH ?= x86_64
 
 # External tools and flags
-HAREC = harec
-HAREFLAGS =
-QBE = qbe
-AS = as
-LD = ld
-AR = ar
-SCDOC = scdoc
+HAREC ?= harec
+HAREFLAGS ?=
+QBE ?= qbe
+AS ?= as
+LD ?= ld
+AR ?= ar
+SCDOC ?= scdoc
 
 # Where to store build artifacts
-HARECACHE = .cache
+HARECACHE ?= .cache

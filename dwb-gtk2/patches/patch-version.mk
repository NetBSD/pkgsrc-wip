$NetBSD: patch-version.mk,v 1.1 2015/05/27 17:59:19 f8l Exp $

Allows overriding REAL_VERSION, which is originally date-based.

--- version.mk.orig	2014-03-07 11:39:43.000000000 +0000
+++ version.mk
@@ -1,5 +1,5 @@
 BUILDDATE=`date +%Y.%m.%d`
-REAL_VERSION=$(BUILDDATE)
+REAL_VERSION?=$(BUILDDATE)
 
 BUILDDATE=`date +%Y.%m.%d`
 GIT_VERSION=$(shell git log -1 --format="%cd %h" --date=short 2>/dev/null)

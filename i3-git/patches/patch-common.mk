$NetBSD$

Allow setting VERSION and prevent overwriting it.

--- common.mk.orig	2016-01-11 23:36:55.000000000 +0000
+++ common.mk
@@ -20,9 +20,11 @@ endif
 
 # In dist tarballs, the version is stored in the I3_VERSION and VERSION files.
 I3_VERSION := '$(shell [ -f $(TOPDIR)/I3_VERSION ] && cat $(TOPDIR)/I3_VERSION)'
-VERSION := '$(shell [ -f $(TOPDIR)/VERSION ] && cat $(TOPDIR)/VERSION)'
-ifeq ('',$(I3_VERSION))
+VERSION ?= '$(shell [ -f $(TOPDIR)/VERSION ] && cat $(TOPDIR)/VERSION)'
+ifeq ('',$(VERSION))
 VERSION := $(shell git describe --tags --abbrev=0)
+endif
+ifeq ('',$(I3_VERSION))
 I3_VERSION := '$(shell git describe --tags --always) ($(shell git log --pretty=format:%cd --date=short -n1), branch \"$(shell git describe --tags --always --all | sed s:heads/::)\")'
 endif
 

$NetBSD: patch-mk_rt.mk,v 1.1 2014/07/03 03:11:32 schmonz Exp $

Detect NetBSD.

--- mk/rt.mk.orig	2014-06-27 19:52:28.000000000 +0000
+++ mk/rt.mk
@@ -171,6 +171,8 @@ else ifeq ($(OSTYPE_$(1)), apple-ios)
   JEMALLOC_ARGS_$(1) := --disable-tls
 else ifeq ($(OSTYPE_$(1)), unknown-freebsd)
   LIBUV_OSTYPE_$(1) := freebsd
+else ifeq ($(OSTYPE_$(1)), -netbsd)
+  LIBUV_OSTYPE_$(1) := netbsd
 else ifeq ($(OSTYPE_$(1)), linux-androideabi)
   LIBUV_OSTYPE_$(1) := android
   LIBUV_ARGS_$(1) := PLATFORM=android host=android OS=linux

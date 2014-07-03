$NetBSD: patch-mk_platform.mk,v 1.1 2014/07/03 03:11:32 schmonz Exp $

Copy-paste FreeBSD's stanza as is (XXX likely incorrect)

--- mk/platform.mk.orig	2014-06-27 19:52:28.000000000 +0000
+++ mk/platform.mk
@@ -552,6 +552,33 @@ CFG_RUN_x86_64-w64-mingw32=PATH="$(CFG_L
 CFG_RUN_TARG_x86_64-w64-mingw32=$(call CFG_RUN_x86_64-w64-mingw32,$(HLIB$(1)_H_$(CFG_BUILD)),$(2))
 RUSTC_CROSS_FLAGS_x86_64-w64-mingw32 :=
 
+# x86_64--netbsd configuration
+CC_x86_64--netbsd=$(CC)
+CXX_x86_64--netbsd=$(CXX)
+CPP_x86_64--netbsd=$(CPP)
+AR_x86_64--netbsd=$(AR)
+CFG_LIB_NAME_x86_64--netbsd=lib$(1).so
+CFG_STATIC_LIB_NAME_x86_64--netbsd=lib$(1).a
+CFG_LIB_GLOB_x86_64--netbsd=lib$(1)-*.so
+CFG_LIB_DSYM_GLOB_x86_64--netbsd=$(1)-*.dylib.dSYM
+CFG_CFLAGS_x86_64--netbsd := -I/usr/local/include $(CFLAGS)
+CFG_GCCISH_CFLAGS_x86_64--netbsd := -Wall -Werror -g -fPIC -I/usr/local/include $(CFLAGS)
+CFG_GCCISH_LINK_FLAGS_x86_64--netbsd := -shared -fPIC -g -pthread  -lrt
+CFG_GCCISH_DEF_FLAG_x86_64--netbsd := -Wl,--export-dynamic,--dynamic-list=
+CFG_GCCISH_PRE_LIB_FLAGS_x86_64--netbsd := -Wl,-whole-archive
+CFG_GCCISH_POST_LIB_FLAGS_x86_64--netbsd := -Wl,-no-whole-archive
+CFG_DEF_SUFFIX_x86_64--netbsd := .bsd.def
+CFG_LLC_FLAGS_x86_64--netbsd :=
+CFG_INSTALL_NAME_x86_64--netbsd =
+CFG_LIBUV_LINK_FLAGS_x86_64--netbsd := -pthread  -lkvm
+CFG_EXE_SUFFIX_x86_64--netbsd :=
+CFG_WINDOWSY_x86_64--netbsd :=
+CFG_UNIXY_x86_64--netbsd := 1
+CFG_PATH_MUNGE_x86_64--netbsd :=
+CFG_LDPATH_x86_64--netbsd :=
+CFG_RUN_x86_64--netbsd=$(2)
+CFG_RUN_TARG_x86_64--netbsd=$(call CFG_RUN_x86_64--netbsd,,$(2))
+
 # x86_64-unknown-freebsd configuration
 CC_x86_64-unknown-freebsd=$(CC)
 CXX_x86_64-unknown-freebsd=$(CXX)

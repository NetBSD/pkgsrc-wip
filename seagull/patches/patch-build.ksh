$NetBSD: patch-build.ksh,v 1.1 2013/09/02 19:08:24 thomasklausner Exp $

Override OS detection, only Linux and HPUX are supported;
for pkgsrc, treat everything as Linux.

--- build.ksh.orig	2010-10-27 12:30:16.000000000 +0000
+++ build.ksh
@@ -34,6 +34,7 @@ BUILD_DEFAULT_EXEC=RELEASE
 BUILD_TARGET=${BUILD_DEFAULT_TARGET}
 BUILD_EXEC=${BUILD_DEFAULT_EXEC}
 typeset -u BUILD_OS=`uname -s | tr '-' '_' | tr '.' '_' | tr '/' '_' `
+BUILD_OS=LINUX
 BUILD_CODE_DIRECTORY=code
 BUILD_DIRECTORY=`pwd`
 typeset -u BUILD_ARCH=`uname -m | tr '-' '_' | tr '.' '_' | tr '/' '_' `

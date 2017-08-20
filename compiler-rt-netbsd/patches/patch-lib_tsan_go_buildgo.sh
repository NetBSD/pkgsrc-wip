$NetBSD$

--- lib/tsan/go/buildgo.sh.orig	2017-07-24 13:39:38.000000000 +0000
+++ lib/tsan/go/buildgo.sh
@@ -68,6 +68,21 @@ elif [ "`uname -a | grep FreeBSD`" != ""
 		../../sanitizer_common/sanitizer_linux_libcdep.cc
 		../../sanitizer_common/sanitizer_stoptheworld_linux_libcdep.cc
 	"
+elif [ "`uname -a | grep NetBSD`" != "" ]; then
+	SUFFIX="netbsd_amd64"
+	OSCFLAGS="-fno-strict-aliasing -fPIC -Werror"
+	OSLDFLAGS="-lpthread -fPIC -fpie"
+	SRCS="
+		$SRCS
+		../rtl/tsan_platform_linux.cc
+		../../sanitizer_common/sanitizer_posix.cc
+		../../sanitizer_common/sanitizer_posix_libcdep.cc
+		../../sanitizer_common/sanitizer_procmaps_common.cc
+		../../sanitizer_common/sanitizer_procmaps_freebsd.cc
+		../../sanitizer_common/sanitizer_linux.cc
+		../../sanitizer_common/sanitizer_linux_libcdep.cc
+		../../sanitizer_common/sanitizer_stoptheworld_linux_libcdep.cc
+	"
 elif [ "`uname -a | grep Darwin`" != "" ]; then
 	SUFFIX="darwin_amd64"
 	OSCFLAGS="-fPIC -Wno-unused-const-variable -Wno-unknown-warning-option -isysroot $(xcodebuild -version -sdk macosx Path) -mmacosx-version-min=10.7"

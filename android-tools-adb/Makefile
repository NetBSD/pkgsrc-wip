# $NetBSD: Makefile,v 1.4 2015/03/07 21:39:40 tnn2 Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	android-tools-adb-9.0.0_r3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=aosp-mirror/}
GITHUB_PROJECT=	platform_system_core
GITHUB_TAG=	${PKGNAME:S/-tools-adb//}
DIST_SUBDIR=	adb${PKGVERSION_NOREV:R:R}
DISTFILES=	${DEFAULT_DISTFILES} Makefile
SITES.Makefile:=${PATCH_SITES}

PATCH_SITES=	${MASTER_SITE_GITHUB:=freebsd/freebsd-ports/raw/734e5c93a88e/devel/android-tools-adb/files/}
PATCHFILES+=	patch-adb_adb__auth__host.cpp
PATCHFILES+=	patch-adb_adb__io__test.cpp
PATCHFILES+=	patch-adb_bugreport__test.cpp
PATCHFILES+=	patch-adb_client_usb__libusb.cpp
PATCHFILES+=	patch-adb_commandline.cpp
PATCHFILES+=	patch-adb_commandline.h
PATCHFILES+=	patch-adb_fdevent__test.cpp
PATCHFILES+=	patch-adb_sysdeps.h
PATCHFILES+=	patch-adb_sysdeps__test.cpp
PATCHFILES+=	patch-adb_sysdeps_posix_network.cpp
PATCHFILES+=	patch-adb_transport__usb.cpp
PATCHFILES+=	patch-adb_usb.h
PATCHFILES+=	patch-base_file.cpp
PATCHFILES+=	patch-base_file__test.cpp
PATCHFILES+=	patch-base_include_android-base_logging.h
PATCHFILES+=	patch-base_logging.cpp
PATCHFILES+=	patch-base_parsenetaddress.cpp
PATCHFILES+=	patch-base_stringprintf__test.cpp
PATCHFILES+=	patch-gtest-1.8.1
PATCHFILES+=	patch-include_cutils_trace.h
PATCHFILES+=	patch-libcrypto__utils_android__pubkey.c
PATCHFILES+=	patch-libcutils_threads.cpp
PATCHFILES+=	patch-liblog_logger__write.c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.android.com/tools/help/adb.html
COMMENT=	Android debug bridge command line tool
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
GCC_REQD+=		5.3 # c++14
USE_TOOLS+=		pkg-config
USE_BSD_MAKEFILE=	yes
MAKE_FILE=		${_DISTDIR}/Makefile
MAKE_ENV+=		MDNSEXT=_unsupported # XXX expose as option
CXXFLAGS+=		$${PIE_CFLAGS} # XXX move to bsd.sys.mk
BUILD_DIRS=		adb
INSTALLATION_DIRS=	bin

.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

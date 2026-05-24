# $NetBSD$

DISTNAME=	android-tools-35.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nmeum/}android-tools/releases/download/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nmeum/android-tools/
COMMENT=	Unoffical CMake-based build system for Android CLI utils
LICENSE=	apache-2.0

CONFLICTS+=	android-tools-adb-[0-9]*

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake perl

GCC_REQD+=	10		# C++17 + designated initializers

# Required by upstream's build for a couple of helpers (per README).
BUILD_DEPENDS+=	go-[0-9]*:../../lang/go

REPLACE_PYTHON+=		vendor/avb/avbtool.py
REPLACE_PYTHON+=		vendor/mkbootimg/mkbootimg.py
REPLACE_PYTHON+=		vendor/mkbootimg/repack_bootimg.py
REPLACE_PYTHON+=		vendor/mkbootimg/unpack_bootimg.py
REPLACE_PYTHON+=		vendor/libufdt/utils/src/mkdtboimg.py

CHECK_PORTABILITY_SKIP+=	vendor/logging/logcat/logcatd.sh
CHECK_PORTABILITY_SKIP+=	vendor/extras/ioshark/compile-only.sh
CHECK_PORTABILITY_SKIP+=	vendor/extras/ioshark/collect-straces-ftraces.sh

.include "../../mk/bsd.prefs.mk"
.include "../../lang/python/application.mk"

# XXX fastboot's USB backend has heavy Linux-isms (linux/usbdevice_fs.h,
# epoll). Constrain to platforms where upstream is known to build.
.if ${OPSYS} == "Linux" || ${OPSYS} == "Darwin"
PLIST_SRC=	${PKGDIR}/PLIST
.else
PLIST_SRC=	${PKGDIR}/PLIST.adb-only
.endif

LDFLAGS.Darwin+=	-framework CoreFoundation -framework IOKit

.include "../../archivers/brotli/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

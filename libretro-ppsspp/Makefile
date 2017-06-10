# $NetBSD$

PKGNAME=	libretro-ppsspp-20161215
CATEGORIES=	emulators

HOMEPAGE=	https://wiki.libretro.com/index.php?title=PPSSPP
COMMENT=	Libretro core based on the PPSSPP PlayStation Portable emulator
LICENSE=	gnu-gpl-v2

PPSSPP_TAG=	5f7bcf7bfc15f83d405bcecd7a163a55ad1e7573
NATIVE_TAG=	9baedbcc2a07b3bccc6d8b8d170498111b990adc
ARMIPS_TAG=	8bd93be9ba715d2f5723857edacf936ae904d07c

DISTFILES+=	${PPSSPP_TAG}.tar.gz
SITES.${PPSSPP_TAG}.tar.gz= \
		${MASTER_SITE_GITHUB:=libretro/libretro-ppsspp/archive/}

DISTFILES+=	${NATIVE_TAG}.tar.gz
SITES.${NATIVE_TAG}.tar.gz= \
		${MASTER_SITE_GITHUB:=libretro/ppsspp-native/archive/}

DISTFILES+=	${ARMIPS_TAG}.tar.gz
SITES.${ARMIPS_TAG}.tar.gz= \
		${MASTER_SITE_GITHUB:=Kingcom/armips/archive/}

WRKSRC=		${WRKDIR}/libretro-ppsspp-${PPSSPP_TAG}/libretro

USE_TOOLS=	gmake pkg-config
USE_LANGUAGES=	c c++

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
CFLAGS+=		-marm
BUILD_MAKE_FLAGS+=	ARCH=arm
.elif !empty(MACHINE_ARCH:M*aarch64*)
BUILD_MAKE_FLAGS+=	ARCH=arm64
.elif !empty(MACHINE_ARCH:M*x86_64*)
BUILD_MAKE_FLAGS+=	ARCH=x86_64
.endif

BUILD_MAKE_FLAGS+=	FFMPEGLDFLAGS="`pkg-config --libs libavformat libavcodec libswresample libswscale`"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

post-extract:
	${MV} ${WRKDIR}/ppsspp-native-${NATIVE_TAG}/* ${WRKSRC}/../native
	${MV} ${WRKDIR}/armips-${ARMIPS_TAG}/* ${WRKSRC}/../ext/armips

do-install:
	${INSTALL_LIB} ${WRKSRC}/ppsspp_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/ppsspp_libretro.so

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../mk/pthread.buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

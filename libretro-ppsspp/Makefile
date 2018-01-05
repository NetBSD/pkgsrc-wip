# $NetBSD$

PKGNAME=	libretro-ppsspp-20171126
CATEGORIES=	emulators

HOMEPAGE=	https://docs.libretro.com/library/ppsspp/
COMMENT=	Libretro core based on the PPSSPP PlayStation Portable emulator
LICENSE=	gnu-gpl-v2

PPSSPP_TAG=	abee4eb1c967467a4c1886a9174738eb37577496
ARMIPS_TAG=	770365d44df35d6e675c58bb2a774ca412278ef5

DISTFILES+=	${PPSSPP_TAG}.tar.gz
SITES.${PPSSPP_TAG}.tar.gz= \
		${MASTER_SITE_GITHUB:=libretro/libretro-ppsspp/archive/}

DISTFILES+=	${ARMIPS_TAG}.tar.gz
SITES.${ARMIPS_TAG}.tar.gz= \
		${MASTER_SITE_GITHUB:=Kingcom/armips/archive/}

WRKSRC=		${WRKDIR}/libretro-ppsspp-${PPSSPP_TAG}
BUILD_DIRS=	libretro

USE_TOOLS=	gmake pkg-config
USE_LANGUAGES=	c c++
EXTRACT_USING=	bsdtar

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
CFLAGS+=		-marm
BUILD_MAKE_FLAGS+=	WITH_DYNAREC=arm
.elif !empty(MACHINE_ARCH:M*x86_64*)
BUILD_MAKE_FLAGS+=	WITH_DYNAREC=x86_64
.elif !empty(MACHINE_ARCH:M*i386*)
BUILD_MAKE_FLAGS+=	WITH_DYNAREC=x86
.endif

BUILD_MAKE_FLAGS+=	FFMPEGLDFLAGS="`pkg-config --libs libavformat libavcodec libavutil libswresample libswscale`"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

post-extract:
	${MV} ${WRKDIR}/armips-${ARMIPS_TAG}/* ${WRKSRC}/ext/armips

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro/ppsspp_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/ppsspp_libretro.so

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../mk/pthread.buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

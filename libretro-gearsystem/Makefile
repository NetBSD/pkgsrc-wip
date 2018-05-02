# $NetBSD$

DISTNAME=	libretro-gearsystem-20180416
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=drhelius/}
GITHUB_PROJECT=	Gearsystem
GITHUB_TAG=	4ca3b977df9eae08368dfe2db28c3e613f182213

HOMEPAGE=	https://docs.libretro.com/library/gearsystem/
COMMENT=	Libretro core for Sega Master System emulation
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
BUILD_DIRS=	platforms/libretro
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/platforms/libretro/gearsystem_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/gearsystem_libretro.so

.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	libretro-mame2003-20170807
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=MAME_2003
COMMENT=	Libretro core based on the Multiple Arcade Machine Emulator (v0.78)
LICENSE=	no-commercial-use

GITHUB_PROJECT=	mame2003-libretro
GITHUB_TAG=	982f31742e13f3083a31c8627eb6bf77824e3c2a

USE_TOOLS=	gmake
EXTRACT_USING=	bsdtar

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
BUILD_MAKE_FLAGS+=	BIGENDIAN=1
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mame2003_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mame2003_libretro.so

.include "../../mk/bsd.pkg.mk"

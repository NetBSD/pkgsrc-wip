# $NetBSD$

DISTNAME=	libretro-mame2003-20171204
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/mame_2003/
COMMENT=	Libretro core based on the Multiple Arcade Machine Emulator (v0.78)
LICENSE=	no-commercial-use

GITHUB_PROJECT=	mame2003-libretro
GITHUB_TAG=	830402e63d645e5477b3be84e0c11db36d620498

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

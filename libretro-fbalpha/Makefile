# $NetBSD$

DISTNAME=	libretro-fbalpha-0.2.97.42.20171123
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Final_Burn_Alpha
COMMENT=	Libretro core based on the FB Alpha arcade emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	fbalpha
GITHUB_TAG=	7332926d40c376a716c973bb1ea39171e4437b53

USE_TOOLS=	gmake

MAKE_FILE=	makefile.libretro

USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
BUILD_MAKE_FLAGS+=	ENDIANNESS_DEFINES=-DWORDS_BIGENDIAN
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fbalpha_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fbalpha_libretro.so

.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	libretro-snes9x2010-20180507
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	snes9x2010
GITHUB_TAG=	fc2457e0235328142a4bc79b46dd05228a9748f4

HOMEPAGE=	https://docs.libretro.com/library/snes9x_2010/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	no-commercial-use

MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/snes9x2010_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x2010_libretro.so

.include "../../mk/bsd.pkg.mk"

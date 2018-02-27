# $NetBSD$

DISTNAME=	libretro-snes9x2010-20180218
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	snes9x2010
GITHUB_TAG=	b9be098d2ea37a5af672e3580d463fc3a89f3902

HOMEPAGE=	https://docs.libretro.com/library/snes9x_2010/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	no-commercial-use

MAKE_FILE=	Makefile.libretro
USE_TOOLS=	gmake

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

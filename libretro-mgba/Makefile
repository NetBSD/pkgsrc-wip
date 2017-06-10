# $NetBSD$

DISTNAME=	libretro-mgba-20170329
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=MGBA
COMMENT=	Libretro core based on the mGBA emulator
LICENSE=	mpl-2.0

GITHUB_PROJECT=	mgba
GITHUB_TAG=	1e95e8913a3d98b897573be1f0b5906394671b10

USE_TOOLS=	gmake

MAKE_FILE=	Makefile.libretro

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mgba_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mgba_libretro.so

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*armv6*) || !empty(MACHINE_ARCH:M*armv7*)
.include "options.mk"
.endif

.include "../../mk/bsd.pkg.mk"

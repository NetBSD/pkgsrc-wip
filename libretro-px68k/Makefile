# $NetBSD$

DISTNAME=	libretro-px68k-20170806
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	px68k-libretro
GITHUB_TAG=	8f6be979ca47396e5b692d288b31825fb1d45c92

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/px68k/
COMMENT=	Libretro core based on the PX68K SHARP X68000 emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/px68k_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/px68k_libretro.so

.include "../../mk/bsd.pkg.mk"

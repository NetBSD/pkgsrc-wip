# $NetBSD$

DISTNAME=	libretro-vecx-20170709
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=Vecx
COMMENT=	Libretro core for Vectrex emulation
LICENSE=	gnu-gpl-v3

GITHUB_TAG=	b47eb91aba80906b6dca1eee698958cdd2deb0d1

MAKE_FILE=	Makefile.libretro

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/vecx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/vecx_libretro.so

.include "../../mk/bsd.pkg.mk"

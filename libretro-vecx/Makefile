# $NetBSD$

DISTNAME=	libretro-vecx-20170718
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/vecx/
COMMENT=	Libretro core for Vectrex emulation
LICENSE=	gnu-gpl-v3

GITHUB_TAG=	eb30b0cc200f32651f402192d8e5516d72f05dc5

MAKE_FILE=	Makefile.libretro

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/vecx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/vecx_libretro.so

.include "../../mk/bsd.pkg.mk"

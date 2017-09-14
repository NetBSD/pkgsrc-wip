# $NetBSD$

DISTNAME=	libretro-parallel-n64-20170907
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

COMMENT=	Libretro core for Nintendo 64 emulation
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	parallel-n64
GITHUB_TAG=	c052e43f382c6162956fc35df21081abb4f5b1cb

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++
EXTRACT_USING=	bsdtar

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

.include "options.mk"

do-install:
	${INSTALL_LIB} ${WRKSRC}/parallel_n64_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/parallel_n64_libretro.so

.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	libretro-parallel-n64-20180522
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	parallel-n64
GITHUB_TAG=	cf95ae02b1819d21570edafdeea314de38ec4975

COMMENT=	Libretro core for Nintendo 64 emulation
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
EXTRACT_USING=	bsdtar

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

.include "options.mk"

do-install:
	${INSTALL_LIB} ${WRKSRC}/parallel_n64_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/parallel_n64_libretro.so

.include "../../mk/bsd.pkg.mk"

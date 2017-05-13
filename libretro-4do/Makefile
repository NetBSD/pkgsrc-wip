# $NetBSD$

DISTNAME=	libretro-4do-20170423
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
COMMENT=	Libretro core based on the 4DO 3DO emulator

GITHUB_PROJECT=	4do-libretro
GITHUB_TAG=	1c3ee3cd4a327ad87fb7fcfd93fddc851119cb6b	

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/4do_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/4do_libretro.so

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2015/02/13 21:21:03 snj Exp $

DISTNAME=	libretro-vba-next-20170123
CATEGORIES=	emulators games
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/vbam-libretro
COMMENT=	Libretro core based on the VBA Next Game Boy Advance emulator

LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	vba-next
GITHUB_TAG=	e7734756d228ea604f8fa872cea1bba987780791

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

MAKE_FILE=	Makefile.libretro

INSTALLATION_DIRS=	lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/vba_next_libretro.so \
		${DESTDIR}${PREFIX}/lib/libretro/vba_next_libretro.so

.include "../../mk/bsd.pkg.mk"

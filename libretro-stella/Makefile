# $NetBSD: Makefile,v 1.1 2015/02/05 22:38:59 jmcneill Exp $

DISTNAME=	libretro-stella-20170124
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/stella/
COMMENT=	Libretro core based on the Stella Atari 2600 (VCS) emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	stella-libretro
GITHUB_TAG=	cdbc9cc4e105ef884ac441cbd3f14d2d4eb47ba4

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/stella_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/stella_libretro.so

.include "../../mk/bsd.pkg.mk"

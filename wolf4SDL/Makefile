# $NetBSD: Makefile,v 1.1 2015/08/17 20:10:44 yhardy Exp $
#

DISTNAME=		Wolf4SDL-1.7-src
PKGNAME=		Wolf4SDL-1.7
CATEGORIES=		games
MASTER_SITES=		http://homepage.o2mail.de/mkroll/bins/
EXTRACT_SUFX=		.zip
EXTRACT_OPTS_ZIP=	-aqo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://homepage.o2mail.de/mkroll/
COMMENT=	Wolfenstein 3D ported to SDL
LICENSE=	xdoom-license AND mame-license

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

CFLAGS+=	-DCARMACIZED -DUPLOAD

BUILD_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

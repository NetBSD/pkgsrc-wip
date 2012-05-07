# $NetBSD: Makefile,v 1.1.1.1 2012/05/07 11:09:31 thomasklausner Exp $
#

DISTNAME=	hyperrogue-35
CATEGORIES=	games
MASTER_SITES=	http://www.roguetemple.com/z/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.roguetemple.com/z/hyper.php
COMMENT=	Rogue clone in a strange, non-Euclidean world
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	hyper

INSTALLATION_DIRS=	bin share/doc/hyperrogue

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hyper ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/hyperrogue.html ${DESTDIR}${PREFIX}/share/doc/hyperrogue

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

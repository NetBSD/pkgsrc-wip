# $NetBSD: Makefile,v 1.3 2010/01/18 09:38:32 thomasklausner Exp $
#

DISTNAME=	silvertree-0.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.silvertreerpg.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.silvertreerpg.org/
COMMENT=	Silver Tree, an open source role playing game

WRKSRC=		${WRKDIR}/silvertree
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-boost-regex=boost_regex-mt

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

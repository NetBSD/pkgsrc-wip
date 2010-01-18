# $NetBSD: Makefile,v 1.9 2010/01/18 09:38:26 thomasklausner Exp $
#

DISTNAME=		kyra_src_2_0_7
PKGNAME=		kyra2-2.0.7
WRKSRC=			${WRKDIR}/kyra
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kyra/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kyra.sourceforge.net/
COMMENT=		Sprite engine

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFLICTS+=		kyra-*

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

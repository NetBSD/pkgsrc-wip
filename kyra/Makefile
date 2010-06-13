# $NetBSD: Makefile,v 1.13 2010/06/13 22:47:09 thomasklausner Exp $
#

DISTNAME=		kyra_src_1_6_5
PKGNAME=		kyra-1.6.5
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kyra/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kyra.sourceforge.net/
COMMENT=		Sprite engine in C++ that uses SDL library

CONFLICTS+=		kyra2-*

WRKSRC=			${WRKDIR}/kyra
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

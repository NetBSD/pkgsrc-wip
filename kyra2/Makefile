# $NetBSD: Makefile,v 1.3 2004/09/23 05:59:44 jlamwww Exp $
#

DISTNAME=		kyra_src_2_0_7
PKGNAME=		kyra2-2.0.7
WRKSRC=			${WRKDIR}/kyra
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kyra/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://kyra.sourceforge.net/
COMMENT=		Sprite engine

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFLICTS+=		kyra-*

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

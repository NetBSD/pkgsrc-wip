# $NetBSD: Makefile,v 1.2 2004/08/17 18:28:25 tvierling Exp $
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
LIBTOOL_LA_FILES+=	lib/libkyra.la
GNU_CONFIGURE=		yes
CONFLICTS+=		kyra-*

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2004/03/07 02:45:14 mpasternak Exp $
#

DISTNAME=		kyra_src_1_6_5
PKGNAME=		kyra-1.6.5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kyra/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://kyra.sourceforge.net/
COMMENT=		Sprite engine in C++ that uses SDL library

CONFLICTS+=		kyra2-*

WRKSRC=			${WRKDIR}/kyra
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

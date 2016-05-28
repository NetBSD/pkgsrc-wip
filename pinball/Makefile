# $NetBSD: Makefile,v 1.11 2012/10/05 11:31:52 asau Exp $
#

DISTNAME=	pinball-0.2.0a
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pinball/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://pinball.sourceforge.net/
COMMENT=	Pinball using the Allegro game library


USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR}/pinball-0.2.0

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.5 2004/04/05 13:30:20 thomasklausner Exp $
#

DISTNAME=	pinball-0.2.0a
WRKSRC=		${WRKDIR}/pinball-0.2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pinball/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://pinball.sourceforge.net/
COMMENT=	Pinball using the Allegro game library

USE_BUILDLINK3= YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=  YES

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.6 2005/02/13 20:46:49 rillig Exp $
#

DISTNAME=	pinball-0.2.0a
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pinball/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://pinball.sourceforge.net/
COMMENT=	Pinball using the Allegro game library

USE_BUILDLINK3= YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=  YES
WRKSRC=		${WRKDIR}/pinball-0.2.0

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

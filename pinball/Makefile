# $NetBSD: Makefile,v 1.4 2004/01/25 02:33:15 grantbeattie Exp $
#

DISTNAME=	pinball-0.2.0a
WRKSRC=		${WRKDIR}/pinball-0.2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pinball/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://pinball.sourceforge.net/
COMMENT=	Pinball using the Allegro game library

USE_BUILDLINK2= YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=  YES

.include "../allegro/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2003/04/12 12:34:11 virtus Exp $
#

DISTNAME=	pinball-0.2.0a
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pinball/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://pinball.sourceforge.net
COMMENT=	Pinball using the Allegro game library

WRKSRC=		${WRKDIR}/pinball-0.2.0
USE_BUILDLINK2= YES
USE_GMAKE=	YES
GNU_CONFIGURE=  YES

.include "../allegro//buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

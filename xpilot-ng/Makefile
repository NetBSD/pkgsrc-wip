# $NetBSD: Makefile,v 1.1.1.1 2004/02/26 21:02:42 pulahti Exp $

DISTNAME=	xpilot-4.5.4X2
PKGNAME=	xpilot-ng-4.5.4X2
CATEGORIES=	games
MASTER_SITES=	http://www.hut.fi/~ksoderbl/xpilot/

MAINTAINER=	pulahti@sourceforge.net
HOMEPAGE=	http://xpilot.sourceforge.net/
COMMENT=	Enhanced version of XPilot network space battle

CONFLICTS+=	xpilot-[0-9]*
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes
GNU_CONFIGURE=	yes

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

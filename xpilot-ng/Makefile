# $NetBSD: Makefile,v 1.8 2006/03/18 17:30:08 pulahti Exp $

DISTNAME=	xpilot-ng-4.7.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xpilot/}

MAINTAINER=	vnorrman@cc.hut.fi
HOMEPAGE=	http://xpilot.sourceforge.net/
COMMENT=	Enhanced version of XPilot network space battle

GNU_CONFIGURE=	yes

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

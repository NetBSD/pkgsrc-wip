# $NetBSD: Makefile,v 1.15 2014/01/25 10:45:29 thomasklausner Exp $

DISTNAME=	xpilot-ng-4.7.2
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xpilot/}

MAINTAINER=	vnorrman@cc.hut.fi
HOMEPAGE=	https://xpilot.sourceforge.net/
COMMENT=	Enhanced version of XPilot network space battle
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

REPLACE_PYTHON=	mapconvert.py

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

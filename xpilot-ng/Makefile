# $NetBSD: Makefile,v 1.12 2010/01/18 09:38:35 thomasklausner Exp $

DISTNAME=	xpilot-ng-4.7.2
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xpilot/}

MAINTAINER=	vnorrman@cc.hut.fi
HOMEPAGE=	http://xpilot.sourceforge.net/
COMMENT=	Enhanced version of XPilot network space battle

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

PYTHON_PATCH_SCRIPTS=	mapconvert.py

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

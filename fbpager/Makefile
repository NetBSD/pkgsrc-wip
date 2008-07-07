# $NetBSD: Makefile,v 1.2 2008/07/07 21:56:01 hoka_adam Exp $

DISTNAME=	fbpager-0.1.4
CATEGORIES=	wm x11
MASTER_SITES=	http://fluxbox.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fluxbox.org/fbpager/
COMMENT=	Fluxbox pager with transparency and mouse gestures

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fbpager
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/fbpager/

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

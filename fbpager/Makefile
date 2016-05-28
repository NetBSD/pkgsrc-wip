# $NetBSD: Makefile,v 1.3 2012/09/28 23:21:47 asau Exp $

DISTNAME=	fbpager-0.1.4
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_FREEBSD}
# http://git.fluxbox.org/fbpager.git/

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

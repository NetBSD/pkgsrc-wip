# $NetBSD: Makefile,v 1.1.1.1 2006/05/19 13:39:13 yomram Exp $

DISTNAME=	fbpager-0.1.4
CATEGORIES=	wm x11
MASTER_SITES=	http://fluxbox.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fluxbox.org/fbpager/
COMMENT=	Fluxbox pager with transparency and mouse gestures

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fbpager
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/fbpager/

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

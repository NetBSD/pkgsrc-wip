# $NetBSD$

DISTNAME=	ewm-0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=pwnwriter/}
GITHUB_TAG=	a87eca5610821da7a240231160071bca6a96cfe1

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/pwnwriter/ewm/
COMMENT=	An elegant window manager
LICENSE=	mit

WRKSRC=		${WRKDIR}/ewm-${GITHUB_TAG}/src

INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"

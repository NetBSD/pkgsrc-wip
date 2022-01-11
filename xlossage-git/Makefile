# $NetBSD: Makefile,v 1.18 2018/03/12 11:17:42 wiz Exp $

DISTNAME=	xlossage-0.0.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=/leahneukirchen}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/leahneukirchen/xlossage
COMMENT=	Display pressed keys in X11 in a readable way
LICENSE=	mit

GIT_REPOSITORIES=	xlossage
GIT_REPO.xlossage=	https://github.com/leahneukirchen/xlossage
WRKSRC=			${WRKDIR}/${PKGBASE}

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xlossage ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

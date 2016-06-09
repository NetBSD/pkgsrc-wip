# $NetBSD: Makefile,v 1.2 2015/08/10 22:37:52 yhardy Exp $

GITHUB_PROJECT=	libilbc
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-2.0.2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=TimothyGu/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TimothyGu/libilbc/
COMMENT=	Packaged version of iLBC codec from the WebRTC project
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/libilbc-2.0.2
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libilbc.pc.in

.include "../../mk/bsd.pkg.mk"

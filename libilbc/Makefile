# $NetBSD: Makefile,v 1.1 2015/08/10 22:33:01 yhardy Exp $

GITHUB_PROJECT=	libilbc
VERSION=	2.0.2
DISTNAME=	v${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=TimothyGu/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=TimothyGu/libilbc/}
COMMENT=	Packaged version of iLBC codec from the WebRTC project
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/libilbc-2.0.2
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libilbc.pc.in

.include "../../mk/bsd.pkg.mk"

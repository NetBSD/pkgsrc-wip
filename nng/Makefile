# $NetBSD$

GITHUB_PROJECT=	nng
GITHUB_TAG=	v1.4.0
DISTNAME=	v1.4.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=nanomsg/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nng.nanomsg.org/
COMMENT=	Light-weight brokerless messaging
LICENSE=	mit

WRKSRC=		${WRKDIR}/nng-1.4.0
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "options.mk"

.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	release-1.2.2.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/release-//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=d-bahr/}
GITHUB_PROJECT=	CRCpp
GITHUB_TAG=	refs/tags/${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/d-bahr/CRCpp/
COMMENT=	Easy to use and fast C++ CRC library
LICENSE=	modified-bsd

.include "../../devel/cmake/build.mk"

WRKSRC=			${WRKDIR}/${PKGBASE}-${DISTNAME}
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11
USE_TOOLS=		pkg-config

PKGCONFIG_OVERRIDE+=	cmake/CRCpp.pc.in

.include "../../mk/bsd.pkg.mk"

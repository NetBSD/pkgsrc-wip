# $NetBSD$

DISTNAME=	tabulate-1.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=p-ranav/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/p-ranav/tabulate/
COMMENT=	C++ library for formatting tables
LICENSE=	mit AND boost-license AND modified-bsd

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c++

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

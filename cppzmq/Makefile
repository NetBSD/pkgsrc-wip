# $NetBSD$

GITHUB_PROJECT=	cppzmq
GITHUB_TAG=	v4.6.0
DISTNAME=	v4.6.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeromq/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/zeromq/cppzmq/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/cppzmq-4.6.0
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

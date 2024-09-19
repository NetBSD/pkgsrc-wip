# $NetBSD$

DISTNAME=	Robinhood-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_GITHUB:=Jamonek/}
GITHUB_PROJECT=	Robinhood
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/Jamonek/Robinhood
COMMENT=	Python Framework to make trades with Robinhood Private API
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.13.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

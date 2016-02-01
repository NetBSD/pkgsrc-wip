# $NetBSD$

DISTNAME=	twisted-csp-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twisted-csp/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ubolonton/twisted-csp
COMMENT=	Go-style channels for Twisted


DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=4.1.3:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-twisted>=1.3.0:../../net/py-twisted

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

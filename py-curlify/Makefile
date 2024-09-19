# $NetBSD$

DISTNAME=	curlify-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/curlify/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/oeegor/curlify
COMMENT=	Library to convert python requests object to curl command
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	curlify-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://files.pythonhosted.org/packages/fa/2c/9254b2294d0250291560d78e16e5cd764b8e2caa75d4cad1e8ae9d73899d/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/oeegor/curlify
COMMENT=	Library to convert python requests object to curl command
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

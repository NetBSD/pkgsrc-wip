# $NetBSD$

DISTNAME=	mitmproxy2swagger-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mitmproxy2swagger/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/mitmproxy2swagger/
COMMENT=	Convert mitmproxy captures to OpenAPI 3.0 specification
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-json-stream>=1.3.0:../../wip/py-json-stream
DEPENDS+=	mitmproxy>=8.0.0:../../net/mitmproxy
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.17.21:../../devel/py-ruamel-yaml

USE_LANGUAGES=	# none

# Only for Python 3.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

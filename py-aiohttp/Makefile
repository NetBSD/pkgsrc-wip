# $NetBSD$

DISTNAME=	aiohttp-2.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/aio-libs/aiohttp/
COMMENT=	Async http client/server framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-multidict>=2.1.4:../../wip/py-multidict
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=1.2.0:../../wip/py-async-timeout
DEPENDS+=	${PYPKGPREFIX}-yarl>=0.10.0:../../wip/py-yarl

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

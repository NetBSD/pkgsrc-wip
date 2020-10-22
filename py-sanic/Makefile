# $NetBSD$

VERS=		20.9.0
DISTNAME=	sanic-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=s/${DISTNAME:S/${VERS}//}/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/huge-success/sanic/
COMMENT=	Web server and web framework that's written to go fast
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-multidict>=4.7.6:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-aiofiles>=0.5.0:../../devel/py-aiofiles
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.14.0:../../devel/py-uvloop
DEPENDS+=	${PYPKGPREFIX}-ujson>=2.0.3:../../textproc/py-ujson
DEPENDS+=	${PYPKGPREFIX}-httptools>=0.1.1:../../www/py-httptools
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.16.1:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-websockets>=8.1:../../www/py-websockets

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

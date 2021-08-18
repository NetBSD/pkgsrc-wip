# $NetBSD$

DISTNAME=	matrix-nio-0.18.6
CATEGORIES=	devel chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matrix-nio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/poljar/matrix-nio
COMMENT=	Matrix client library for Python
LICENSE=	isc

# TODO: py36 requires dataclasses
DEPENDS+=	${PYPKGPREFIX}-aiofiles>=0.6.0:../../devel/py-aiofiles
DEPENDS+=	${PYPKGPREFIX}-aiohttp-socks>=0.6.0:../../www/py-aiohttp-socks
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.7.4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.10.1:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-future>=0.18.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-h11>=0.12.0:../../www/py-h11
DEPENDS+=	${PYPKGPREFIX}-h2>=4.0.0:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.2.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-logbook>=1.5.3:../../devel/py-logbook
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64>=1.1.0:../../devel/py-unpaddedbase64
# TODO: py-olm is still wip
DEPENDS+=	${PYPKGPREFIX}-olm>=3.2.2:../../wip/py-olm
DEPENDS+=	${PYPKGPREFIX}-peewee>=3.14.4:../../databases/py-peewee
DEPENDS+=	${PYPKGPREFIX}-cachetools>=4.2.1:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-atomicwrites>=1.4.0:../../devel/py-atomicwrites

# matrix-nio is only supported on python3
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

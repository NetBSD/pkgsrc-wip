# $NetBSD$

DISTNAME=	influxdb-5.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel databases
MASTER_SITES=	${MASTER_SITE_PYPI:=i/influxdb/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/influxdata/influxdb-python
COMMENT=	Python client for InfluxDB
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests>=2.6.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.10.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz:../../time/py-pytz

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

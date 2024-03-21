# $NetBSD$

DISTNAME=	singer-python-6.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/singer-python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/singer-io/singer-python
COMMENT=	Singer.io utility library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-backoff>=2.2.1:../../wip/py-backoff
DEPENDS+=	${PYPKGPREFIX}-ciso8601>=2.3.1:../../time/py-ciso8601
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.3:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.6.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-pytz>=2018.4:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.13.2:../../converters/py-simplejson

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# only for Python 3

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

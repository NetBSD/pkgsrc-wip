# $NetBSD$

DISTNAME=	target-csv-0.3.0
PKGNAME=	${PYPKGPREFIX}-singer-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/target-csv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/singer-io/target-csv
COMMENT=	Singer.io target for writing CSV files
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.6.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-singer-python>=2.1.4:../../wip/py-singer-python

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# only for Python 3

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} target-csv singer-target-csv${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

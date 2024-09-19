# $NetBSD: Makefile,v 1.4 2015/06/26 23:03:28 othyro Exp $

DISTNAME=	logtools-0.8.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/logtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adamhadani/logtools
COMMENT=	Log files analysis/filtering framework written in Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-ptable>=0.5:../../textproc/py-ptable
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7.9:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlsoup>=0.9.0:../../databases/py-sqlsoup
DEPENDS+=	${PYPKGPREFIX}-acora>=1.7:../../textproc/py-acora

USE_LANGUAGES=	# none
USE_TOOLS+=	bash

REPLACE_BASH+=	scripts/*

REPLACE_PYTHON+=	logtools/__init__.py logtools/_config.py
REPLACE_PYTHON+=	logtools/_filter.py logtools/_filterbots.py
REPLACE_PYTHON+=	logtools/_geoip.py logtools/_join.py logtools/_merge.py
REPLACE_PYTHON+=	logtools/_parse.py logtools/_plot.py logtools/_qps.py
REPLACE_PYTHON+=	logtools/_sample.py logtools/_serve.py
REPLACE_PYTHON+=	logtools/_sumstat.py logtools/_tail.py
REPLACE_PYTHON+=	logtools/_urlparse.py logtools/join_backends.py
REPLACE_PYTHON+=	logtools/parsers.py logtools/test/__init__.py
REPLACE_PYTHON+=	logtools/test/test_logtools.py logtools/utils.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

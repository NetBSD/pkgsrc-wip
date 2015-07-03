# $NetBSD: Makefile,v 1.1 2015/07/03 20:57:28 jihbed Exp $

DISTNAME=	hgapi-1.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/h/hgapi/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://bitbucket.org/haard/hgapi
COMMENT=	Python API to Mercurial using the command-line interface
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.6.5:../../converters/py-simplejson

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	34 33 27

do-test:
	${RUN} cd ${WRKSRC}/hgapi; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testhgapi.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

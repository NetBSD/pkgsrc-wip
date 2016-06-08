# $NetBSD: Makefile,v 1.1 2015/07/03 18:49:26 jihbed Exp $

DISTNAME=	pathlib-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pathlib/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pathlib.readthedocs.org/
COMMENT=	Object-oriented filesystem paths
LICENSE=	mit

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_pathlib.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

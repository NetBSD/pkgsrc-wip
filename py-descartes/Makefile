# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:21 asau Exp $
#

DISTNAME=	descartes-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/descartes/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://bitbucket.org/sgillies/descartes/
COMMENT=	Use geometric objects as matplotlib paths and patches
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/descartes-1.0
PYTHON_VERSIONS_INCOMPATIBLE= 34 35 36 37

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} descartes/tests.py

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

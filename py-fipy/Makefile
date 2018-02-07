# $NetBSD: Makefile,v 1.4 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=	FiPy-2.1.2
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-fipy-2.1.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=F/FiPy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ctcms.nist.gov/fipy/
COMMENT=	Finite volume PDE solver in Python
LICENSE=	public-domain

DEPENDS+=	${PYPKGPREFIX}-gnuplot>=1.8:../../graphics/py-gnuplot
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.4:../../textproc/py-sphinx
#DEPENDS+=	${PYPKGPREFIX}-gist>=1.5.28:../../wip/py-gist

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gnuplot

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/fipy; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

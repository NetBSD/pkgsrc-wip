# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:34 asau Exp $
#

DISTNAME=	FiPy-2.1.2
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-fipy-2.1.2
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/F/FiPy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ctcms.nist.gov/fipy/
COMMENT=	Finite volume PDE solver in Python
LICENSE=	public-domain

DEPENDS+=	${PYPKGPREFIX}-gnuplot>=1.8:../../graphics/py-gnuplot
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.4:../../textproc/py-sphinx
#DEPENDS+=	${PYPKGPREFIX}-gist>=1.5.28:../../wip/py-gist

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/fipy; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

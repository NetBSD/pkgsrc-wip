# $NetBSD$

DISTNAME=	control-0.6d
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://downloads.sourceforge.net/project/python-control/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://python-control.sourceforge.net
COMMENT=	Python Control Systems Library
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_all.py

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"

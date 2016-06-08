# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:43 thomasklausner Exp $

DISTNAME=	nodepy-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nodepy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://numerics.kaust.edu.sa/nodepy/
COMMENT=	Numerical ODE solvers in Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} unit_tests.py

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.2:../../math/py-sympy
.include "../../mk/bsd.pkg.mk"

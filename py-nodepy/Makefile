# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:28 asau Exp $
#

DISTNAME=	nodepy-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/n/nodepy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://web.kaust.edu.sa/faculty/davidketcheson/NodePy/
COMMENT=	Numerical ODE solvers in Python
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/nodepy-0.3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} unit_tests.py

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

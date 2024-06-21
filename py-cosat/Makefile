# $NetBSD$

DISTNAME=	pycosat-0.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycosat/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ContinuumIO/pycosat
COMMENT=	bindings to picosat (a SAT solver)
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_pycosat.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

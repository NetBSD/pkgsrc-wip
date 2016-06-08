# $NetBSD$

DISTNAME=	pycosat-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycosat/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ContinuumIO/pycosat
COMMENT=	bindings to picosat (a SAT solver)
LICENSE=	mit

WRKSRC=	${WRKDIR}/pycosat-0.6.1

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_pycosat.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

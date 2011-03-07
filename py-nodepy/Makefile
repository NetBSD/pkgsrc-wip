# $NetBSD: Makefile,v 1.1.1.1 2011/03/07 10:50:33 jihbed Exp $
#

DISTNAME=	nodepy-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/n/nodepy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://web.kaust.edu.sa/faculty/davidketcheson/NodePy/
COMMENT=	Numerical ODE solvers in Python
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/nodepy-0.3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} unit_tests.py

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

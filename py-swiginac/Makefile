# $NetBSD: Makefile,v 1.4 2014/05/09 07:38:50 thomasklausner Exp $

DISTNAME=	swiginac-1.5.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://download.berlios.de/swiginac/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://swiginac.berlios.de/
COMMENT=	Interface to GiNaC, providing Python with symbolic mathematics
LICENSE=	cpl-1.0

USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-Numeric

do-test:
	${RUN} cd ${WRKSRC}/tests/Symbolic; ${SETENV} ${TEST_ENV} ${PYTHONBIN} SymbolicTests.py
	${RUN} cd ${WRKSRC}/tests/swiginac; ${SETENV} ${TEST_ENV} ${PYTHONBIN} checkall.py

.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../wip/libginac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

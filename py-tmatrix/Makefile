# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:47 thomasklausner Exp $

DISTNAME=	pytmatrix-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	https://github.com/jleinonen/pytmatrix/releases/download/0.2.1/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/jleinonen/pytmatrix
COMMENT=	Python code for T-matrix scattering calculations
LICENSE=	mit

PYDISTUTILSPKG=	yes

USE_LANGUAGES=	c fortran

do-test:
	${RUN} cd ${WRKSRC}/pymatrix/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_tmatrix.py

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"

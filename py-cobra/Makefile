# $NetBSD: Makefile,v 1.1 2015/08/05 20:35:45 jihbed Exp $

DISTNAME=	cobra-0.4.0b1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cobra/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://opencobra.github.io/cobrapy
COMMENT=	Constraints-based modeling of biological networks
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

WRKSRC=	${WRKDIR}/cobra-0.4.0b1

REPLACE_PYTHON+=	cobra/test/data/update_pickles.py

do-test:
	${RUN} cd ${WRKSRC}/cobra; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_all.py


.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

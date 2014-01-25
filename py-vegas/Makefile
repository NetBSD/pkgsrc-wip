# $NetBSD: Makefile,v 1.2 2014/01/25 10:38:23 thomasklausner Exp $

DISTNAME=	vegas-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/v/vegas/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/v/vegas/
COMMENT=	Tools for adaptive multidimensional Monte Carlo integration
LICENSE=	gnu-gpl-v3

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS+= share/doc/vegas

do-test:
	${RUN} cd ${WRKSRC}/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_vegas.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/vegas.pdf ${DESTDIR}${PREFIX}/share/doc/vegas

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-lsqfit>=4.5.3:../../wip/py-lsqfit
.include "../../mk/bsd.pkg.mk"

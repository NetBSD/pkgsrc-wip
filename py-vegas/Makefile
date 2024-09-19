# $NetBSD: Makefile,v 1.3 2014/06/01 12:49:47 thomasklausner Exp $

DISTNAME=	vegas-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vegas/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/v/vegas/
COMMENT=	Tools for adaptive multidimensional Monte Carlo integration
LICENSE=	gnu-gpl-v3

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS+=	share/doc/vegas

do-test:
	${RUN} cd ${WRKSRC}/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_vegas.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/vegas.pdf ${DESTDIR}${PREFIX}/share/doc/vegas

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-lsqfit>=4.5.3:../../wip/py-lsqfit
.include "../../mk/bsd.pkg.mk"

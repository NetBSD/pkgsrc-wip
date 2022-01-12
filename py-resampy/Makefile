# $NetBSD: Makefile,v 1.13 2022/01/04 20:52:34 wiz Exp $

DISTNAME=	resampy-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/resampy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bmcfee/resampy
COMMENT=	Efficient sample rate conversion in Python
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-numba-[0-9]*:../../math/py-numba
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

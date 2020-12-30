# $NetBSD$

DISTNAME=	qupulse-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/f7/73/6becb468cb8b430967396b938ea2c8584507558909913ad0b9800529eac3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/qutech/qupulse
COMMENT=	Quantum compUting PULse parametrization and SEquencing framework
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cached-property>=1.5.1:../../devel/py-cached-property
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=8.4.0:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.1.1:../../math/py-sympy

TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=3.2.3:../../devel/py-test-benchmark

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_API_DEPENDS.py-numpy+=        ${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

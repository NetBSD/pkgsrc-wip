# $NetBSD$

DISTNAME=	ortho-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/ortho/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ameli/ortho
COMMENT=	Generate orthogonal set of functions
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner>=5.2:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.9:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.6.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-seaborn>=0.9.0:../../graphics/py-seaborn
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.8
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

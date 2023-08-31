# $NetBSD$

DISTNAME=	einsteinpy_geodesics-0.1.0
PKGNAME=	${PYPKGPREFIX}-einsteinpy-geodesics-0.1.0
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/b6/8a/54ac0cfe8af60bd898631f16f03a23c78f72e8a3c7e7b372cbbf306c867e/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/einsteinpy/einsteinpy-geodesics
COMMENT=	Julia solver for geodesics in the Kerr family of spacetimes
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-coverage>=5.2.1:../../devel/py-coverage
TOOL_DEPENDS+=	${PYPKGPREFIX}-isort>=4.3.21:../../devel/py-isort
TOOL_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.782:../../devel/py-codestyle
TOOL_DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.6.0:../../lang/py-mypy
TOOL_DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-doctestplus>=0.8.0:../../devel/py-test-doctestplus
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-mpl>=0.11:../../devel/py-test-mpl
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-mypy>=0:../../devel/py-test-mypy
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-remotedata>=0:../../net/py-test-remotedata
TOOL_DEPENDS+=	${PYPKGPREFIX}-alabaster>=0.7.12:../../textproc/py-alabaster
TOOL_DEPENDS+=	${PYPKGPREFIX}-tox>=3.12.1:../../devel/py-tox
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8.5:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

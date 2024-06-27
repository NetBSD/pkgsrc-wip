# $NetBSD$

DISTNAME=	psygnal-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psygnal/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://pypi.org/project/psygnal/
COMMENT=	Fast python callback/event system modeled after Qt signals
LICENSE=	original-bsd

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.24.2:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-dask-[0-9]*:../../wip/py-dask
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-pydantic-[0-9]*:../../devel/py-pydantic
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-wrapt-[0-9]*:../../devel/py-wrapt
TEST_DEPENDS+=	${PYPKGPREFIX}-msgspec-[0-9]*:../../devel/py-msgspec
TEST_DEPENDS+=	${PYPKGPREFIX}-toolz-[0-9]*:../../devel/py-toolz

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

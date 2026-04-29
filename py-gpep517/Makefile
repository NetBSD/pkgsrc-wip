# $NetBSD$

DISTNAME=	gpep517-19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gpep517/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/gpep517/
COMMENT=	Python package builder and installer for non-pip-centric world
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
#TEST_DEPENDS+=	${PYPKGPREFIX}-pdm-pep517-[0-9]*:../../devel/py-pdm-pep517
TEST_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	gpep517

# 18 failed, 97 passed, 2 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

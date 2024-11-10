# $NetBSD$

DISTNAME=	cityhash-0.4.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=	python-cityhash
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=escherba/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/escherba/cityhash
COMMENT=	Python wrapper for FarmHash and CityHash
LICENSE=	modified-bsd
PKGREVISION=	2

WRKSRC=	${WRKDIR}/python-${DISTNAME}

PYTHON_VERSIONS_INCOMPATIBLE=	27
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.41:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=68:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-cpuinfo>=9.0.0:../../sysutils/py-cpuinfo
DEPENDS+=	cityhash-[0-9]*:../../textproc/cityhash
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

TEST_ENV+=	PYTHONPATH=${WRKSRC}/src
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py build_ext -i
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

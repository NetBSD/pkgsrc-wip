# $NetBSD$

DISTNAME=	swh.graph-0.2.9
PKGNAME=	${PYPKGPREFIX}-swh-graph-0.2.9
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.graph/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DGRPH
COMMENT=	Software Heritage graph service
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.7.3:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-py4j>=0.10.9.1:../../wip/py-py4j
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.7.3:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.7.2:../../wip/py-swh-model
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.0:../../devel/py-test

PKG_JVMS_ACCEPTED=	sun-jdk7 openjdk7 oracle-jdk8 openjdk8

.include "../../lang/python/egg.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

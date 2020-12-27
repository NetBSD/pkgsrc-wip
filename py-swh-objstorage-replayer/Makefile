# $NetBSD$

DISTNAME=	swh.objstorage.replayer-0.2.1
PKGNAME=	${PYPKGPREFIX}-swh-objstorage-replayer-0.2.1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.objstorage.replayer/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/swh-objstorage-replayer
COMMENT=	Software Heritage content replayer
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-storage>=0.13.1:../../wip/py-swh-storage
DEPENDS+=	${PYPKGPREFIX}-swh-journal>=0.4.2:../../wip/py-swh.journal
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

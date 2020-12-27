# $NetBSD$

DISTNAME=	swh.loader.pypi-0.0.9
PKGNAME=	${PYPKGPREFIX}-swh-loader-pypi-0.0.9
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.loader.pypi/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/source/swh-loader-pypi
COMMENT=	Software Heritage PyPI Loader
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-arrow>=0.15.8:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-vcversioner>=2.16.0.0:../../devel/py-vcversioner
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.6.1:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-swh-loader-core>=0.11.0:../../wip/py-swh-loader-core
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.7.2:../../wip/py-swh-model
DEPENDS+=	${PYPKGPREFIX}-swh-storage>=0.0.83:../../wip/py-swh-storage
DEPENDS+=	${PYPKGPREFIX}-swh-scheduler>=0.0.39:../../wip/py-swh-scheduler
DEPENDS+=	${PYPKGPREFIX}-swh-loader-core>=0.0.37:../../wip/py-swh-loader-core

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

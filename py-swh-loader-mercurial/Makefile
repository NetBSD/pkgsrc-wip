# $NetBSD$

DISTNAME=	swh.loader.mercurial-0.1.0
PKGNAME=	${PYPKGPREFIX}-swh-loader-mercurial-0.1.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.loader.mercurial/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DLDHG/
COMMENT=	Software Heritage Mercurial Loader
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-billiard>=3.6.3.0:../../parallel/py-billiard
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-patool>=1.12:../../wip/py-patool
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-hglib>=2.6.2:../../devel/py-hglib
DEPENDS+=	${PYPKGPREFIX}-retrying>=1.3.3:../../wip/py-retrying
DEPENDS+=	${PYPKGPREFIX}-sqlitedict>=1.7.0:../../wip/py-sqlitedict
DEPENDS+=	${PYPKGPREFIX}-swh-loader-core>=0.11.0:../../wip/py-swh-loader-core
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.7.2:../../wip/py-swh-model
DEPENDS+=	${PYPKGPREFIX}-swh-scheduler>=0.4.0:../../wip/py-swh-scheduler
DEPENDS+=	${PYPKGPREFIX}-swh-storage>=0.13.1:../../wip/py-swh-storage

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

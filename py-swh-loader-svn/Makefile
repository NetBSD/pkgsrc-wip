# $NetBSD$

DISTNAME=	swh.loader.svn-0.5.0
PKGNAME=	${PYPKGPREFIX}-swh-loader-svn-0.5.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.loader.svn/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DLDSVN
COMMENT=	Software Heritage Loader SVN
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-retrying>=1.3.3:../../wip/py-retrying
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-subvertpy>=0.9.4:../../devel/py-subvertpy
DEPENDS+=	${PYPKGPREFIX}-swh-storage>=0.0.83:../../wip/py-swh-storage
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.7.2:../../wip/py-swh-model
DEPENDS+=	${PYPKGPREFIX}-swh-scheduler>=0.0.39:../../wip/py-swh-scheduler
DEPENDS+=	${PYPKGPREFIX}-swh-loader-core>=0.0.37:../../wip/py-swh-loader-core

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	swh.loader.tar-0.0.41
PKGNAME=	${PYPKGPREFIX}-swh-loader-tar-0.0.41
CATEGORIES=	archive python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.loader.tar/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DLDTAR
COMMENT=	Software Heritage Tarball Loader
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-arrow>=0.15.8:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-vcversioner>=2.16.0.0:../../devel/py-vcversioner
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.7.2:../../wip/py-swh-model
DEPENDS+=	${PYPKGPREFIX}-swh-scheduler>=0.0.39:../../wip/py-swh-scheduler
DEPENDS+=	${PYPKGPREFIX}-swh-storage>=0.0.83:../../wip/py-swh-storage
DEPENDS+=	${PYPKGPREFIX}-swh-loader-core>=0.0.35:../../wip/py-swh-loader-core
DEPENDS+=	${PYPKGPREFIX}-swh-loader-dir>=0.0.33:../../wip/py-swh-loader-dir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

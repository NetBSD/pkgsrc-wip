# $NetBSD$

DISTNAME=	swh.objstorage-0.2.2
PKGNAME=	${PYPKGPREFIX}-swh-objstorage-0.2.2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.objstorage/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DOBJS
COMMENT=	Software Heritage Object Storage
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.7.3:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.0.27:../../wip/py-swh-model

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

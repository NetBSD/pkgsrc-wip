# $NetBSD$

DISTNAME=	swh.vault-0.4.0
PKGNAME=	${PYPKGPREFIX}-swh-vault-0.4.0
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.vault/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DVAU/
COMMENT=	Software Heritage vault
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-flask>=1.1.2:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.8.6:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-fastimport>=0.9.8:../../devel/py-fastimport
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.7.2:../../wip/py-swh-model
DEPENDS+=	${PYPKGPREFIX}-swh-objstorage>=0.2.2:../../wip/py-swh-objstorage
DEPENDS+=	${PYPKGPREFIX}-swh-scheduler>=0.0.39:../../wip/py-swh-scheduler
DEPENDS+=	${PYPKGPREFIX}-swh-storage>=0.0.83:../../wip/py-swh-storage

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	swh.storage-0.18.0
PKGNAME=	${PYPKGPREFIX}-swh-storage-0.18.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.storage/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DSTO/
COMMENT=	Software Heritage storage manager
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-flask>=1.1.2:../../www/py-flask
#DEPENDS+=	${PYPKGPREFIX}-psycopg2>=0:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.7.3:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-cassandra-driver>=3.15.1:../../databases/py-cassandra-driver
DEPENDS+=	${PYPKGPREFIX}-Deprecated>=1.2.7:../../devel/py-Deprecated
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=0.4.3:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-iso8601>=0.1.13:../../time/py-iso8601
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.7.2:../../wip/py-swh-model
DEPENDS+=	${PYPKGPREFIX}-swh-objstorage>=0.2.2:../../wip/py-swh-objstorage
DEPENDS+=	${PYPKGPREFIX}-tenacity>=6.2.0:../../wip/py-tenacity

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

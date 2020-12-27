# $NetBSD$

DISTNAME=	swh.indexer-0.6.3
PKGNAME=	${PYPKGPREFIX}-swh-indexer-0.6.3
CATEGORIES=	category python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.indexer/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/78/
COMMENT=	Software Heritage Content Indexer
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-magic>=0.4.13:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-ld>=2.0.3:../../wip/py-ld
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0.12.0:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.7.2:../../wip/py-swh-model
DEPENDS+=	${PYPKGPREFIX}-swh-objstorage>=0.2.2:../../wip/py-swh-objstorage
DEPENDS+=	${PYPKGPREFIX}-swh-scheduler>=0.0.39:../../wip/py-swh-scheduler
DEPENDS+=	${PYPKGPREFIX}-swh-storage>=0.0.83:../../wip/py-swh-storage
DEPENDS+=	${PYPKGPREFIX}-swh-journal>=0.1.0:../../wip/py-swh-journal

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

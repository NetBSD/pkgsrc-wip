# $NetBSD$

DISTNAME=	swh.search-0.2.3
PKGNAME=	${PYPKGPREFIX}-swh-search-0.2.3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.search/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DSEA
COMMENT=	Software Heritage search service
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27


DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-elasticsearch>=6.2.0:../../databases/py-elasticsearch
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-journal>=0.5.1:../../wip/py-swh-journal
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.0.27:../../wip/py-swh-model

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

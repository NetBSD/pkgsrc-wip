# $NetBSD$

DISTNAME=	wasserplan-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wasserplan/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/vrdi/geometry-of-graph-partitions
COMMENT=	1-Wasserstein distances between districting plans
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-gerrychain>=0.2.12:../../wip/py-gerrychain
DEPENDS+=	${PYPKGPREFIX}-cvxpy>=0.2.15:../../wip/py-cvxpy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

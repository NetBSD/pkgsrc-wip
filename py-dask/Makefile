# $NetBSD$

DISTNAME=	dask-0.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/60/3d/e8778209da4d7b5aa54c59fa62d91fd1601d2dab21497752b98cc51ae364/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/dask/dask/
COMMENT=	Dask is a flexible parallel computing library for analytics
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-toolz>=0.7.1:../../wip/py-toolz

WRKSRC=		${WRKDIR}/dask-0.10.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

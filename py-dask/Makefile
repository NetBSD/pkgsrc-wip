# $NetBSD$

DISTNAME=	dask-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/45/78/da8e4a5625e71566ff2af73c3ce61d7846c7405917fd1f15d5d15d4d06a6/


MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/dask/dask/
COMMENT=	Dask is a flexible parallel computing library for analytics
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-toolz>=0.7.1:../../wip/py-toolz

WRKSRC=		${WRKDIR}/dask-0.11.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	xarray-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/6a/be/484dacd98f21506961bf67fd5b0dc62a128869e6a1f9716266e846aa6a82/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pydata/xarray
COMMENT=	N-D labeled arrays and datasets in Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.1:../../math/py-pandas

WRKSRC=		${WRKDIR}/xarray-0.8.2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

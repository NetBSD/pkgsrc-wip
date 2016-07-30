# $NetBSD$

DISTNAME=	Pymote-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/Pymote/}
EXTRACT_SUFX=	.zip#md5=cdf3b1648f1eded58ef02a234fe0a194

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/darbula/pymote
COMMENT=	Python library for simulation of distributed algorithms
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ipython>=3.2.1:../../devel/py-ipython

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	datashape-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/datashape/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://datashape.readthedocs.org/en/latest/
COMMENT=	Data description language
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-multipledispatch>=0.6.0:../../devel/py-multipledispatch

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.7
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

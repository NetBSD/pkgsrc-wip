# $NetBSD$

DISTNAME=	holoviz-0.11.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=h/holoviz/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://holoviz.org/
COMMENT=	High-level tools to simplify visualization in Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.19.4:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-xarray>=0.15.1:../../math/py-xarray
DEPENDS+=	${PYPKGPREFIX}-colorcet>=2.0.2:../../wip/py-colorcet
DEPENDS+=	${PYPKGPREFIX}-ct>=0.4.8:../../wip/py-ct
DEPENDS+=	${PYPKGPREFIX}-dask-[0-9]*:../../wip/py-dask
DEPENDS+=	${PYPKGPREFIX}-param>=1.10.0:../../wip/py-param
	
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

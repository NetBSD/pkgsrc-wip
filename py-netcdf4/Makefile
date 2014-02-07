# $NetBSD: Makefile,v 1.1 2014/02/07 23:24:54 jihbed Exp $

DISTNAME=	netCDF4-1.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/n/netCDF4/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/netcdf4-python/
COMMENT=	Python/numpy interface to netCDF library (versions 3 and 4)
LICENSE=	mit

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

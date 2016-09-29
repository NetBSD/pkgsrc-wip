# $NetBSD$

DISTNAME=	netCDF4-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/netCDF4/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/netcdf4-python/
COMMENT=	Python/numpy interface to netCDF library (versions 3 and 4)
LICENSE=	mit

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

do-test:
	${RUN} cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_all.py

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

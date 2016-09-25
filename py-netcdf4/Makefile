# $NetBSD$

DISTNAME=	netCDF4-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/b2/a3/8ddc328fd9067e98f03884fb7de5900c43cbe609eb75b3fd516c211a1012/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/netcdf4-python/
COMMENT=	Python/numpy interface to netCDF library (versions 3 and 4)
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=	${WRKDIR}/netCDF4-1.2.4

USE_TOOLS+= pkg-config

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

do-test:
	${RUN} cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_all.py



.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

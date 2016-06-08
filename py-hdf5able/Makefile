# $NetBSD: Makefile,v 1.1 2014/09/06 21:09:16 jihbed Exp $

DISTNAME=	hdf5able-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hdf5able/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/hdf5able/
COMMENT=	Serialisation interface from ndarray-focused objects to HDF5
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-h5py>=2.2.1:../../devel/py-h5py

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

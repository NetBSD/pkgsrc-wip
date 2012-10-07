# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:43 asau Exp $
#

DISTNAME=	h5py-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES= devel python
MASTER_SITES=	http://h5py.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/h5py/
COMMENT=	Python interface to the HDF5 library
LICENSE=	modified-bsd

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

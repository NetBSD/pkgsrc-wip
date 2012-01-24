# $NetBSD: Makefile,v 1.1.1.1 2012/01/24 21:40:16 jihbed Exp $
#

DISTNAME=	h5py-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES= devel python
MASTER_SITES=	http://h5py.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/h5py/
COMMENT=	Python interface to the HDF5 library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

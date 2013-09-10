# $NetBSD: Makefile,v 1.3 2013/09/10 23:13:30 jihbed Exp $

DISTNAME=	h5py-2.2.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://h5py.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/h5py/
COMMENT=	Python interface to the HDF5 library
LICENSE=	modified-bsd

PYDISTUTILSPKG=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.h5py
PKG_SUPPORTED_OPTIONS=	mpi
PKG_SUGGESTED_OPTIONS=	mpi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpi)
DEPENDS+=	${PYPKGPREFIX}-mpi4py>=1.3.1:../../wip/py-mpi4py
.include "../../devel/py-cython/buildlink3.mk"
.endif


.include "../../devel/hdf5/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
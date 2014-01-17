# $NetBSD: Makefile,v 1.4 2014/01/17 21:02:44 jihbed Exp $

DISTNAME=	h5py-2.2.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://www.h5py.org/dl/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.h5py.org
COMMENT=	Python interface to the HDF5 library
LICENSE=	modified-bsd

PYDISTUTILSPKG=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.h5py
PKG_SUPPORTED_OPTIONS=	cython
PKG_SUGGESTED_OPTIONS=	cython

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcython)
.include "../../devel/py-cython/buildlink3.mk"
.endif

.include "../../devel/hdf5/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

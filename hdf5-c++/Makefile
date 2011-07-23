# $NetBSD: Makefile,v 1.1.1.1 2011/07/23 22:48:40 alnsn Exp $

PKGNAME=	hdf5-c++-${HDF5_VER}
COMMENT=	Hierarchical Data Format (new generation) - C++ wrappers

USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-cxx

.include "../../wip/hdf5/Makefile.common"

.include "../../wip/hdf5/buildlink3.mk"

# Since the package is build from source code shared with hdf5,
# same options should be passed:
.if !empty(PKG_BUILD_OPTIONS.hdf5:Mszip)
CONFIGURE_ARGS+=	--with-szlib
.endif

.if !empty(PKG_BUILD_OPTIONS.hdf5:Mthreads)
CONFIGURE_ARGS+=	--enable-threadsafe
.endif

.include "../../mk/bsd.pkg.mk"

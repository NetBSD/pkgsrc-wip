# $NetBSD$

.include "Makefile.common"

COMMENT=	Library for handling standard particle formats

CMAKE_CONFIGURE_ARGS+=	-DPARTIO_BUILD_LIB:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DPARTIO_BUILD_SHARED_LIBS:BOOL=ON

.include "../../devel/cmake/build.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

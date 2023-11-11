# $NetBSD$

.include "../../wip/partio/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Python bindings for partio

CMAKE_CONFIGURE_ARGS+=	-DPARTIO_BUILD_PY:BOOL=ON

PY_PATCHPLIST=	yes

.include "../../devel/cmake/build.mk"

.include "../../devel/swig4/buildlink3.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.partio+=	partio>=${PKGVERSION_NOREV}
.include "../../wip/partio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

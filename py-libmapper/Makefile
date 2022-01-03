# $NetBSD$

.include "../../wip/libmapper/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

USE_TOOLS+=	gmake

COMMENT=	Python bindings for libmapper

BUILD_DIRS=	swig

PY_PATCHPLIST=	yes

.include "../../audio/liblo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/libmapper/buildlink3.mk"
.include "../../wip/swig4/tool.mk"
.include "../../mk/bsd.pkg.mk"

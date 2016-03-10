# $NetBSD$

PKGNAME=	${DISTNAME:S/cfe/clang-static-analyzer/:S/.src//}

DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../wip/clang

USE_TOOLS+=	perl:run

BUILD_TARGET=	clang-check scan-build scan-view

INSTALL_DIRS=	../build/tools/clang-check ../build/tools/scan-build ../build/tools/scan-view

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=ON

REPLACE_PYTHON=	# empty
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 3.5

.include "../../lang/python/application.mk"
.include "../../wip/clang/Makefile.common"

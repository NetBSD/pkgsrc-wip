# $NetBSD$

.include "../../lang/llvm/version.mk"

DISTNAME=	flang-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flang.llvm.org/
COMMENT=	Fortran compiler targeting LLVM
LICENSE=	apache-2.0

DEPENDS+=	bash>=4.4:../../shells/bash

USE_LANGUAGES=		c c++17
USE_CMAKE=		yes
USE_TOOLS+=		gmake

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCLANG_DIR=${BUILDLINK_PREFIX.clang}/lib/cmake/clang
# As of 15.0.5, shared libraries are problematic: building executes
# `flang-new` which is linked against not yet installed shared libraries.
#CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=YES

REPLACE_BASH=	tools/f18/flang-to-external-fc.in

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../wip/mlir/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

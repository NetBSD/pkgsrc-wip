# $NetBSD$

.include "../../wip/llvm/version.mk"

DISTNAME=	flang-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flang.llvm.org/
COMMENT=	Fortran compiler targeting LLVM
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++17
USE_TOOLS+=	bash:run gmake

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DFLANG_INCLUDE_TESTS=OFF
CMAKE_ARGS+=	-DCLANG_DIR=${BUILDLINK_PREFIX.clang}/lib/cmake/clang
# As of 15.0.5, shared libraries are problematic: building executes
# `flang-new` which is linked against not yet installed shared libraries.
#CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=YES

REPLACE_BASH=	tools/f18/flang-to-external-fc.in

.include "../../devel/cmake/build.mk"
.include "../../wip/clang/buildlink3.mk"
.include "../../wip/llvm/buildlink3.mk"
.include "../../wip/mlir/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

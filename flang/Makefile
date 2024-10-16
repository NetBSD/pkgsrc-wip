# $NetBSD$

.include "../../wip/llvm/version.mk"

DISTNAME=	flang-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flang.llvm.org/
COMMENT=	Fortran compiler targeting LLVM
LICENSE=	apache-2.0

USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:run gmake
GCC_REQD+=		12

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DFLANG_INCLUDE_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DCLANG_DIR=${BUILDLINK_PREFIX.clang}/lib/cmake/clang
CMAKE_CONFIGURE_ARGS+=	-DLLVM_DIR=${BUILDLINK_PREFIX.llvm}/lib/cmake/llvm
CMAKE_CONFIGURE_ARGS+=	-DMLIR_DIR=${BUILDLINK_PREFIX.llvm}/lib/cmake/mlir
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=YES

REPLACE_BASH=	tools/f18/flang-to-external-fc.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
.endif

.include "../../devel/cmake/build.mk"
.include "../../wip/clang/buildlink3.mk"
.include "../../wip/llvm/buildlink3.mk"
.include "../../wip/mlir/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

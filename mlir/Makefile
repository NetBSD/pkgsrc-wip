# $NetBSD$

.include "../../wip/llvm/version.mk"

PKGNAME=	mlir-${LLVM_VERSION}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mlir.llvm.org/
COMMENT=	Multi-Level Intermediate Representation
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DMLIR_INSTALL_AGGREGATE_OBJECTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DMLIR_BUILD_MLIR_C_DYLIB=ON

# FIXME: ld: library 'MLIR' not found

BUILD_TARGET=	mlir-tblgen mlir-headers mlir-libraries

.include "../../devel/cmake/build.mk"
.include "../../wip/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

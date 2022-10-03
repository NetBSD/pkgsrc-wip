# $NetBSD$

.include "../../lang/llvm/version.mk"

DISTNAME=	llvm-project-${LLVM_VERSION}.src
PKGNAME=	mlir-${LLVM_VERSION}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mlir.llvm.org/
COMMENT=	Multi-Level Intermediate Representation
LICENSE=	apache-2.0

EXTRACT_ELEMENTS=	${DISTNAME}/cmake
EXTRACT_ELEMENTS+=	${DISTNAME}/mlir
WRKSRC=			${WRKDIR}/${DISTNAME}/mlir

USE_LANGUAGES=		c c++14
USE_CMAKE=		yes
USE_TOOLS+=		gmake

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DMLIR_INSTALL_AGGREGATE_OBJECTS=NO
CMAKE_ARGS+=	-DMLIR_BUILD_MLIR_C_DYLIB=YES

.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

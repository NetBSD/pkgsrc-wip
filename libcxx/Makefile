# $NetBSD: Makefile,v 1.17 2022/12/07 10:40:34 jperkin Exp $

.include "../../wip/llvm/version.mk"

EXTRACT_ELEMENTS+=	${DISTNAME}/libc
EXTRACT_ELEMENTS+=	${DISTNAME}/libcxxabi

PKGNAME=	libcxx-${LLVM_VERSION}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libcxx.llvm.org/
COMMENT=	C++ Standard Library
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++20
USE_LANGUAGES=		c c++
SSP_SUPPORTED=		no
GCC_REQD+=		14 # must be in sync with libcxxabi

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DLIBCXX_CXX_ABI=system-libcxxabi
CMAKE_CONFIGURE_ARGS+=	-DLIBCXX_CXX_ABI_INCLUDE_PATHS=${WRKSRC}/../libcxxabi/include
CMAKE_CONFIGURE_ARGS+=	-DLIBCXX_ENABLE_ABI_LINKER_SCRIPT=OFF
CMAKE_CONFIGURE_ARGS+=	-DLIBCXX_INCLUDE_BENCHMARKS=OFF

# avoid conflict with stddef.h
CXXFLAGS.NetBSD+=	-D__DEFINED_max_align_t=1

CXXFLAGS.SunOS+=	-D_LIBCPP_NO_ABI_TAG=1

.include "../../mk/compiler.mk"

.if ${CC_VERSION:Mgcc-[0-9].*} || ${CC_VERSION:Mgcc-10.*}
# Avoid GCC < 11 error https://github.com/llvm/llvm-project/issues/54018
CXXFLAGS+=	-std=c++17 -D_LIBCPP_STD_VER=17
.endif

.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/libcxxabi/buildlink3.mk"
.include "../../wip/libunwind/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

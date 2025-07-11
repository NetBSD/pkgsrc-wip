# $NetBSD: Makefile,v 1.17 2022/12/07 10:40:34 jperkin Exp $

.include "../../wip/llvm/version.mk"

DISTNAME=	libcxx-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libcxx.llvm.org/
COMMENT=	C++ Standard Library
LICENSE=	apache-2.0

# libc isn't officially packaged
# It is needed for src/include/from_chars_floating_point.h
#  git clone -b llvmorg-${LLVM_VERSION} --depth=1 git@github.com:llvm/llvm-project.git
#  cd llvm-project
#  mv libc libc-${LLVM_VERSION}.src
#  bsdtar -cf - libc-${LLVM_VERSION}.src | xz -9c > /dist/distfiles/libc-${LLVM_VERSION}.src.tar.xz
LIBC=		libc-${LLVM_VERSION}.src
EXTRA_DIST+=	${LIBC}${EXTRACT_SUFX}

# libcxx requires libcxxabi's cxxabi.h to build, but libcxxabi requires
# libcxx's includes to build, so we have this unholy extra distfiles thing
# in both of them to get them to build against each other without causing
# circular dependencies.  This must be kept in sync with libcxxabi/Makefile.
LIBCXXABI=	libcxxabi-${LLVM_VERSION}.src
EXTRA_DIST+=	${LIBCXXABI}${EXTRACT_SUFX}

SITES.${LIBCXXABI}${EXTRACT_SUFX}=	\
	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/}

USE_CXX_FEATURES=	c++20
USE_LANGUAGES=		c c++
SSP_SUPPORTED=		no
GCC_REQD+=		14 # must be in sync with libcxxabi

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DLIBCXX_CXX_ABI=system-libcxxabi
CMAKE_CONFIGURE_ARGS+=	-DLIBCXX_CXX_ABI_INCLUDE_PATHS=${WRKDIR}/${LIBCXXABI}/include
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

post-extract:
	${LN} -f -s ${WRKDIR}/${LIBC} ${WRKDIR}/libc
	${LN} -f -s ${WRKDIR}/${LIBCXXABI} ${WRKDIR}/libcxxabi

.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/libcxxabi/buildlink3.mk"
.include "../../wip/libunwind/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2015/04/25 10:01:54 krytarowski Exp $

GIT_REPOSITORIES=	coreclr
GIT_REPO.coreclr=	https://github.com/dotnet/coreclr.git

DISTNAME=	coreclr
PKGNAME=	coreclr-0.0.0
CATEGORIES=	devel

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/dotnet/coreclr
COMMENT=	The .NET Core runtime and the base library
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash pax
# We need to set CMake this way to get defined CMAKE_CONFIGURE_ARGS
USE_CMAKE=	yes
CMAKE_CONFIGURE_ARGS+=	-DCORECLR_SET_RPATH:BOOL=OFF

REPLACE_BASH+=	build.sh src/pal/tests/palsuite/runpaltests.sh

CORECLR_PREFIX=	${PREFIX}/CoreCLR

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
CORECLR_ARCH=	x64
.endif

CORECLR_OBJDIR=		${WRKSRC}/bin/obj/${OPSYS}.${CORECLR_ARCH}.Debug
CORECLR_PRODUCTDIR=	${WRKSRC}/bin/Product/${OPSYS}.${CORECLR_ARCH}.Debug

# Handle subprefix
LDFLAGS+=	${COMPILER_RPATH_FLAG}${CORECLR_PREFIX:Q}
LDFLAGS+=	${COMPILER_RPATH_FLAG}${CORECLR_PREFIX:Q}/Loader/NativeLibs
LDFLAGS+=	${COMPILER_RPATH_FLAG}${CORECLR_PREFIX:Q}/bin

BUILDLINK_PASSTHRU_DIRS+=	${CORECLR_PREFIX:Q}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${CORECLR_PREFIX:Q}

# DOTNET targets only LLVM
PKGSRC_COMPILER=	clang
PKG_CC=			clang
PKG_CXX=		clang++
_WRAP_EXTRA_ARGS.CXX+=	-Wno-unused-function -Wno-self-assign
CWRAPPERS_APPEND.cxx+=	-Wno-unused-function -Wno-self-assign


TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/bin/obj/${OPSYS}.x64.Debug/src/pal/tests/palsuite/exception_handling/pal_sxs/test1

do-configure:
	${RUN} ${ECHO} Skip configure and call CMake via build.sh

do-build:
	${RUN} cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} PYTHON=${PYTHONBIN:Q} \
		./build.sh skipmscorlib cmakeargs ${CMAKE_CONFIGURE_ARGS:Q}

# Currently there is no unix-like install target.
# Put all produced files under subprefix.
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${CORECLR_PREFIX:Q}
	cd ${CORECLR_PRODUCTDIR} && ${PAX} -rw . ${DESTDIR}${CORECLR_PREFIX:Q}

do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} src/pal/tests/palsuite/runpaltests.sh \
		${CORECLR_OBJDIR} ${WRKSRC}/paltestout

.include "../../textproc/icu/buildlink3.mk"
# Stable LLVM
#.include "../../lang/llvm/buildlink3.mk"
#.include "../../devel/lldb/buildlink3.mk"
#.include "../../lang/clang/buildlink3.mk"
#.include "../../lang/libunwind/buildlink3.mk"
# Devel LLVM
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../wip/lldb-git/buildlink3.mk"
.include "../../wip/clang-git/buildlink3.mk"
.include "../../wip/libunwind-git/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2015/04/25 10:01:54 krytarowski Exp $

GIT_REPOSITORIES=	coreclr
GIT_REPO.coreclr=	https://github.com/dotnet/coreclr.git

DISTNAME=	coreclr
PKGNAME=	coreclr-0.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dotnet/coreclr
COMMENT=	The .NET Core runtime and the base library
LICENSE=	mit

# We need to set CMake this way to get defined CMAKE_ARGS
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	bash
REPLACE_BASH+=	build.sh

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CMAKE_ARGS+=	-DCORECLR_SET_RPATH=OFF

do-configure:
	${RUN} ${ECHO} Skip configure and call CMake via build.sh

do-build:
	${RUN} cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${CONFIGURE_ENV} PYTHON=${PYTHONBIN:Q} ./build.sh skipmscorlib cmakeargs ${CMAKE_ARGS:Q}

do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} ${BASH} src/pal/tests/palsuite/runpaltests.sh ${WRKSRC}/bin/obj/NetBSD.x64.Debug ${WRKSRC}/paltestout

.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../wip/lldb-git/buildlink3.mk"
.include "../../wip/clang-git/buildlink3.mk"
.include "../../wip/libunwind-git/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

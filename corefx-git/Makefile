# $NetBSD: Makefile,v 1.3 2015/04/25 10:01:54 krytarowski Exp $

GIT_REPOSITORIES=	corefx
GIT_REPO.corefx=	https://github.com/dotnet/corefx.git

DISTNAME=	corefx
PKGNAME=	corefx-0.0.0
CATEGORIES=	devel

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/dotnet/corefx
COMMENT=	The .NET Core foundational libraries
LICENSE=	mit

# We need to set CMake this way to get defined CMAKE_ARGS
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	bash
REPLACE_BASH+=	build.sh

# DOTNET targets only LLVM
PKGSRC_COMPILER=	clang
PKG_CC=			clang
PKG_CXX=		clang++

# NetBSD specific for now
CMAKE_ARGS+=	-DHeimdalGssApi=ON

do-configure:
	${RUN} ${ECHO} Skip configure and call CMake via build.sh

do-build:
	${RUN} cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} ./build.sh native verbose cmakeargs ${CMAKE_ARGS:Q}

# NetBSD uses Heimdal from base
#.include "../../security/mit-krb5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"

# Stable LLVM
#.include "../../lang/llvm/buildlink3.mk"
#.include "../../devel/lldb/buildlink3.mk"
#.include "../../lang/clang/buildlink3.mk"
# Devel LLVM
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../wip/lldb-git/buildlink3.mk"
.include "../../wip/clang-git/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

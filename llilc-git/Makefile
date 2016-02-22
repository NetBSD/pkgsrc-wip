# $NetBSD: Makefile,v 1.3 2015/04/25 10:01:54 krytarowski Exp $

GIT_REPOSITORIES=	llilc
GIT_REPO.llilc=	https://github.com/dotnet/llilc.git

DISTNAME=	llilc
PKGNAME=	llilc-0.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dotnet/llilc
COMMENT=	LLVM based compiler for .NET Core
LICENSE=	mit

WRKSRC=		${WRKDIR}/llilc
CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	bash
REPLACE_BASH+=	build.sh

CMAKE_ARGS+=	-DWITH_CORECLR:PATH=${PREFIX}/CoreCLR

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../wip/coreclr-git/buildlink3.mk"
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../wip/lldb-git/buildlink3.mk"
.include "../../wip/clang-git/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

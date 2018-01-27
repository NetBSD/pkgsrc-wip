# $NetBSD: Makefile,v 1.3 2015/04/25 10:01:54 krytarowski Exp $

GIT_REPOSITORIES=	nuget
GIT_REPO.nuget=		https://github.com/NuGet/NuGet.Client.git

DISTNAME=	nuget
PKGNAME=	nuget-0.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nuget.org/
COMMENT=	Core client libraries for NuGet Services
LICENSE=	apache-2.0

#USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	bash
REPLACE_BASH+=	build.sh

do-build:
		${RUN} cd ${WRKSRC} && PYTHON=${PYTHONBIN} ./build.sh

.include "../../textproc/icu/buildlink3.mk"
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../wip/lldb-git/buildlink3.mk"
.include "../../wip/clang-git/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

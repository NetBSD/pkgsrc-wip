# $NetBSD: Makefile,v 1.3 2015/04/25 10:01:54 krytarowski Exp $

GIT_REPOSITORIES=	corert
GIT_REPO.corert=	https://github.com/dotnet/corert.git

DISTNAME=	corert
PKGNAME=	corert-0.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dotnet/corert
COMMENT=	Microsoft .NET Core runtime optimized for AOT scenarios
LICENSE=	mit

#USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	bash
REPLACE_BASH+=	build.sh

do-build:
		${RUN} cd ${WRKSRC} && PYTHON=${PYTHONBIN} ./build.sh

.include "../../lang/mono/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../devel/lldb/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

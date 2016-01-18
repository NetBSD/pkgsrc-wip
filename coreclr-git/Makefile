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

#USE_CMAKE=	yes
#USE_LANGUAGES=	c c++

USE_TOOLS+=	bash
REPLACE_BASH+=	build.sh

do-build:
		${RUN} cd ${WRKSRC} && ./build.sh


.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2015/04/13 00:54:30 krytarowski Exp $

GIT_REPOSITORIES=	coreclr
GIT_REPO.coreclr=	git@github.com:dotnet/coreclr.git

DISTNAME=	coreclr
PKGNAME=	coreclr-0.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dotnet/coreclr
COMMENT=	The .NET Core runtime and the base library
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

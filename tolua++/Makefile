# $NetBSD$

PKGNAME=	tolua++-1.0.93
DISTNAME=	toluapp-${PKGVERSION_NOREV}
CATEGORIES=	devel
GITHUB_PROJECT=	toluapp
MASTER_SITES=	${MASTER_SITE_GITHUB:=LuaDist/}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://github.com/LuaDist/toluapp
COMMENT=	Tool to integrate C/C++ code with Lua
LICENSE=	mit

USE_CMAKE=	yes

.include "../../lang/lua51/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

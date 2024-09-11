# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	cffi-lua-0.2.3
PKGNAME=	lua-cffi-0.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=q66/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/q66/cffi-lua/
COMMENT=	Portable C FFI for Lua
LICENSE=	mit

USE_LANGUAGES=		c++
USE_CXX_FEATURES=	c++14
USE_TOOLS+=		pkg-config
WRKSRC=			${WRKDIR}/${DISTNAME}

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

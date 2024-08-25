# $NetBSD$

PKGNAME=	luabind-0.9.2
CATEGORIES=	devel
HG_REPO=	https://hg.kervala.net/luabind
HG_TAG=		d579cb61c2d2

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	${HG_REPO}
COMMENT=	Lua bindings for C++
LICENSE=	mit

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes
CMAKE_CONFIGURE_ARGS+=	-DWITH_LUA53:BOOL=ON

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../lang/lua53/buildlink3.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"

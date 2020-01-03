# $NetBSD$

DISTNAME=	lua-term-0.7
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hoelzro/}
GITHUB_PROJECT=	lua-term
GITHUB_TAG=	0.07

HOMEPAGE=	https://github.com/hoelzro/lua-term
COMMENT=	Lua module for manipulating a terminal
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_CDIR}

MAKE_ENV+=	LUA_DIR=${PREFIX}
MAKE_ENV+=	LUA_VER=${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}
MAKE_ENV+=	LUA_INC=${PREFIX}/${LUA_INCDIR}
MAKE_ENV+=	LUA_LIBDIR=${PREFIX}/${LUA_CDIR}/term
MAKE_ENV+=	LUA_SHARE=${PREFIX}/${LUA_LDIR}/term
MAKE_ENV+=	OPSYS=${OPSYS}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"

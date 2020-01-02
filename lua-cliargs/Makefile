# $NetBSD$

DISTNAME=	lua-cliargs-3.0
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=amireh/}
GITHUB_PROJECT=	lua_cliargs
GITHUB_TAG=	v${PKGVERSION_NOREV}-2

HOMEPAGE=	https://github.com/amireh/lua_cliargs
COMMENT=	Command-line argument parsing module for Lua
LICENSE=	mit

NO_BUILD=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/cliargs
INSTALLATION_DIRS+=	${LUA_LDIR}/cliargs/utils

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/cliargs.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/src/cliargs/*.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/cliargs
	${INSTALL_DATA} ${WRKSRC}/src/cliargs/utils/*.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/cliargs/utils

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"

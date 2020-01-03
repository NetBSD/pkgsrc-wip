# $NetBSD$

DISTNAME=	lua-luacheck-0.23.0
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mpeterv/}
GITHUB_PROJECT=	luacheck

HOMEPAGE=	https://github.com/mpeterv/luacheck
COMMENT=	Tool for linting and static analysis of Lua code
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-argparse-[0-9]*:../../wip/lua-argparse

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/lua-//}

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_LDIR}/luacheck ${LUA_LDIR}/luacheck/stages ${PREFIX}/bin

PLIST_SUBST+=	LUADOTVER=${_LUA_DOT_VERSION}

SUBST_CLASSES+=			lua_interp
SUBST_MESSAGE.lua_interp=	Fixing default lua path
SUBST_STAGE.lua_interp=		post-extract
SUBST_FILES.lua_interp=		bin/luacheck.lua
SUBST_SED.lua_interp=		-e 's,/usr/bin/env lua,${LUA_INTERPRETER},g'

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/luacheck/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/luacheck/
	${INSTALL_DATA} ${WRKSRC}/src/luacheck/stages/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/luacheck/stages/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/luacheck.lua ${DESTDIR}${PREFIX}/bin/luacheck${_LUA_DOT_VERSION}.lua


.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

PKGNAME=	luakit-0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=aidanholm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aidanholm.github.io/luakit/
COMMENT=	Webkit based browser framework extensible by Lua
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

GIT_REPOSITORIES=	luakit
GIT_BRANCH.luakit=	develop
GIT_REPO.luakit=	git://github.com/aidanholm/luakit
WRKSRC=			${WRKDIR}/luakit

CONF_FILES+=	${PREFIX}/share/examples/luakit/binds.lua	${PREFIX}/etc/xdg/luakit/binds.lua
CONF_FILES+=	${PREFIX}/share/examples/luakit/globals.lua	${PREFIX}/etc/xdg/luakit/globals.lua
CONF_FILES+=	${PREFIX}/share/examples/luakit/modes.lua	${PREFIX}/etc/xdg/luakit/modes.lua
CONF_FILES+=	${PREFIX}/share/examples/luakit/rc.lua		${PREFIX}/etc/xdg/luakit/rc.lua
CONF_FILES+=	${PREFIX}/share/examples/luakit/theme.lua	${PREFIX}/etc/xdg/luakit/theme.lua
CONF_FILES+=	${PREFIX}/share/examples/luakit/webview.lua	${PREFIX}/etc/xdg/luakit/webview.lua
CONF_FILES+=	${PREFIX}/share/examples/luakit/webview_wm.lua	${PREFIX}/etc/xdg/luakit/webview_wm.lua
CONF_FILES+=	${PREFIX}/share/examples/luakit/window.lua	${PREFIX}/etc/xdg/luakit/window.lua

# luakit tries to open the X11 display while generating API documentation
# ... but does not actually use X11 for this step
MAKE_ENV+=		DISPLAY=
LUAKIT_MAKE_FLAGS+=	DEVELOPMENT_PATHS=0
LUAKIT_MAKE_FLAGS+=	DOCDIR=${DESTDIR}${PREFIX}/share/doc/luakit
LUAKIT_MAKE_FLAGS+=	MANPREFIX=${DESTDIR}${PREFIX}/${PKGMANDIR}
LUAKIT_MAKE_FLAGS+=	USE_LUAJIT=0
BUILD_MAKE_FLAGS+=	${LUAKIT_MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	${LUAKIT_MAKE_FLAGS}

LUA_VERSIONS_ACCEPTED=	51

.include "../../lang/lua/luaversion.mk"

DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../wip/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

PKGNAME=	luakit-0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=luakit/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://luakit.org/
COMMENT=	Webkit based browser framework extensible by Lua
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

GIT_REPOSITORIES=	luakit
GIT_BRANCH.luakit=	develop
GIT_REPO.luakit=	git://github.com/luakit/luakit
WRKSRC=			${WRKDIR}/luakit

MAKE_FLAGS+=	DEVELOPMENT_PATHS=0
MAKE_FLAGS+=	APPDIR=${PREFIX}/share/applications
MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/luakit
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	PIXMAPDIR=${PREFIX}/share/pixmaps
MAKE_FLAGS+=	XDGPREFIX=${PKG_SYSCONFDIR}

LUA_VERSIONS_ACCEPTED=	51

.include "../../lang/lua/luaversion.mk"

DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem

OWN_DIRS+=	${PKG_SYSCONFDIR}/xdg/luakit

CONF_FILES+=	${PREFIX}/share/examples/luakit/rc.lua \
		${PKG_SYSCONFDIR}/xdg/luakit/rc.lua

CONF_FILES+=	${PREFIX}/share/examples/luakit/theme.lua \
		${PKG_SYSCONFDIR}/xdg/luakit/theme.lua

# Based on lang/swi-prolog-packages:
setupx:
.if exists(${X11BASE}/bin/Xvfb)
	-${X11BASE}/bin/Xvfb :2 & \
	${ECHO} $$! >${WRKDIR}/.Xvfb.pid
	${ECHO} checkforx: Xvfb-PID: `${CAT} ${WRKDIR}/.Xvfb.pid`
	sleep 5
DISPLAY= :2
.else
	@${ECHO} "Error: Please install Xvfb so that the documentation can be built."
	@${FALSE}
.endif  #Xvfb

MAKE_ENV+=	DISPLAY=${DISPLAY:Q}

teardownx:
	${ECHO} teardownx: Xvfb-PID: `${CAT} ${WRKDIR}/.Xvfb.pid`
	sleep 5
	-kill `${CAT} ${WRKDIR}/.Xvfb.pid`
	${RM} -f ${WRKDIR}/.Xvfb.pid

pre-build:	setupx
post-build:	teardownx

pre-install:
	${RM} -f ${WRKSRC}/lib/*.orig

.include "options.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"

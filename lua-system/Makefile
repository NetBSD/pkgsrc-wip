# $NetBSD$

DISTNAME=	lua-system-0.2.1
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=LuaDist2/}
GITHUB_PROJECT=	luasystem
GITHUB_TAG=	${PKGVERSION_NOREV}-0

HOMEPAGE=	https://github.com/LuaDist2/luasystem
COMMENT=	Platform independent system call library for Lua
LICENSE=	mit

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_CDIR} ${LUA_LDIR}/system

USE_TOOLS+=	gmake pkg-config
# WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}/src
BUILD_DIRS=	src

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
MAKE_ENV+=	PLAT=linux
MAKE_ENV+=	LUAINC_linux=${PREFIX}/${LUA_INCDIR}
.elif ${OPSYS} == "Darwin"
MAKE_ENV+=	PLAT=macosx
MAKE_ENV+=	LUAINC_macosx=${PREFIX}/${LUA_INCDIR}
.else
MAKE_ENV+=	PLAT=freebsd
MAKE_ENV+=	LUAINC_freebsd=${PREFIX}/${LUA_INCDIR}
.endif

MAKE_ENV+=	prefix=${PREFIX}
MAKE_ENV+=	LUA_VERSION=${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}
MAKE_ENV+=	CDIR=${LUA_CDIR}
MAKE_ENV+=	LDIR=${LUA_LDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/system/*.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/system

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"

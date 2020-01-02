# $NetBSD$

DISTNAME=	lua-dkjson-2.5
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	-http://dkolf.de/src/dkjson-lua.fsl/raw/dkjson.lua?name=16cbc26080996d9da827df42cb0844a25518eeb3

EXTRACT_SUFX=	#empty

HOMEPAGE=	http://dkolf.de/src/dkjson-lua.fsl/home
COMMENT=	JSON module written in Lua
LICENSE=	mit

NO_BUILD=	yes
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${CP} $$extract_file ${WRKSRC}/dkjson.lua

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKDIR}/dkjson.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}


.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"

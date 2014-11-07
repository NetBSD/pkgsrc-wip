# $NetBSD: Makefile,v 1.1 2014/11/07 19:20:13 jonthn Exp $

DISTNAME=	0.3.1
PKGNAME=	${LUA_PKGPREFIX}-MessagePack-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=   https://github.com/fperrad/lua-MessagePack/archive/

HOMEPAGE=	http://fperrad.github.io/lua-MessagePack
COMMENT=	MessagePack library for Lua
LICENSE=	mit

WRKSRC=         ${WRKDIR}/lua-MessagePack-${DISTNAME}
NO_BUILD=       yes
NO_CONFIGURE=	yes

.include "../../lang/lua/luaversion.mk"
INSTALLATION_DIRS+=	${LUA_LDIR}

# Just link src dir src{version} to simplify install target
post-extract:
	${LN} -s ${WRKSRC}/src ${WRKSRC}/src5.1
	${LN} -s ${WRKSRC}/src ${WRKSRC}/src5.2

do-install:
	${INSTALL_DATA} ${WRKSRC}/src${_LUA_DOT_VERSION}/MessagePack.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/luaversion.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"

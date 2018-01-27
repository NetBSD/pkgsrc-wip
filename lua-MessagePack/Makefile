# $NetBSD: Makefile,v 1.2 2014/11/08 08:49:01 jonthn Exp $

DISTNAME=	lua-MessagePack-0.3.1
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/1}
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/fperrad/lua-MessagePack/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

HOMEPAGE=	http://fperrad.github.io/lua-MessagePack
COMMENT=	MessagePack library for Lua
LICENSE=	mit

NO_BUILD=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

.include "../../lang/lua/luaversion.mk"
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

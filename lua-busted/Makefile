# $NetBSD$

DISTNAME=	lua-busted-2.0.0
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Olivine-Labs/}
GITHUB_PROJECT=	busted
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/Olivine-Labs/busted
COMMENT=	Elegant Lua unit testing
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-cliargs-[0-9]*:../../wip/lua-cliargs
DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-system-[0-9]*:../../devel/lua-system
DEPENDS+=	${LUA_PKGPREFIX}-dkjson-[0-9]*:../../wip/lua-dkjson
DEPENDS+=	${LUA_PKGPREFIX}-say-[0-9]*:../../wip/lua-say
DEPENDS+=	${LUA_PKGPREFIX}-luassert-[0-9]*:../../wip/lua-luassert
DEPENDS+=	${LUA_PKGPREFIX}-term-[0-9]*:../../devel/lua-term
DEPENDS+=	${LUA_PKGPREFIX}-penlight-[0-9]*:../../devel/lua-penlight
DEPENDS+=	${LUA_PKGPREFIX}-mediator-[0-9]*:../../devel/lua-mediator

NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR} ${PREFIX}/bin
INSTALLATION_DIRS+=	${LUA_LDIR}/busted
INSTALLATION_DIRS+=	${LUA_LDIR}/busted/modules
INSTALLATION_DIRS+=	${LUA_LDIR}/busted/modules/files
INSTALLATION_DIRS+=	${LUA_LDIR}/busted/outputHandlers
INSTALLATION_DIRS+=	${LUA_LDIR}/busted/languages

PLIST_SUBST+=	LUADOTVER=${_LUA_DOT_VERSION}

SUBST_CLASSES+=			lua_interp
SUBST_MESSAGE.lua_interp=	Fixing default lua path
SUBST_STAGE.lua_interp=		post-extract
SUBST_FILES.lua_interp=		bin/busted
SUBST_SED.lua_interp=		-e 's,/usr/bin/env lua,${LUA_INTERPRETER},g'

do-install:
	${INSTALL_DATA} ${WRKSRC}/busted/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/busted/
	${INSTALL_DATA} ${WRKSRC}/busted/modules/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/busted/modules/
	${INSTALL_DATA} ${WRKSRC}/busted/modules/files/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/busted/modules/files/
	${INSTALL_DATA} ${WRKSRC}/busted/outputHandlers/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/busted/outputHandlers/
	${INSTALL_DATA} ${WRKSRC}/busted/languages/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/busted/languages/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/busted ${DESTDIR}${PREFIX}/bin/busted${_LUA_DOT_VERSION}


.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"

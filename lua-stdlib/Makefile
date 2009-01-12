# $NetBSD: Makefile,v 1.5 2009/01/12 19:24:28 cheusov Exp $

.include "../../wip/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/${LUA_PKGPREFIX}-stdlib/}

COMMENT=		Standard library for Lua programming language

INSTALLATION_DIRS+=	${LUA_LDIR}
PLIST_SUBST+=		MODULES_DIR=${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/modules/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"

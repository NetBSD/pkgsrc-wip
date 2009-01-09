# $NetBSD: Makefile,v 1.4 2009/01/09 12:43:46 cheusov Exp $

.include "../../wip/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/lua-stdlib/}

COMMENT=		Standard library for Lua programming language

DEPENDS+=		lua>=5.1:../../lang/lua

# hack! I don't how to get Lua's directory for modules properly
LUA_VER=		5.1
MODULES_DIR=		lib/lua/${LUA_VER}

INSTALLATION_DIRS+=	${MODULES_DIR}
PLIST_SUBST+=		MODULES_DIR=${MODULES_DIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/modules/*.lua \
	                ${DESTDIR}${PREFIX}/${MODULES_DIR}

.include "../../mk/bsd.pkg.mk"

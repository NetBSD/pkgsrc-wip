# $NetBSD: Makefile,v 1.6 2009/01/15 19:22:37 minskim Exp $

.include "../../wip/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/${LUA_PKGPREFIX}-stdlib/}

COMMENT=		Standard library for Lua programming language

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/modules/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"

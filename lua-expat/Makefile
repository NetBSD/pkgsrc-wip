# $NetBSD: Makefile,v 1.2 2004/02/06 21:10:05 blef Exp $
#

DISTNAME=		luaexpat-1.0a
PKGNAME=		${DISTNAME:S/lua/lua-/}
CATEGORIES=		wip
MASTER_SITES=		http://www.keplerproject.org/luaexpat/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.tecgraf.puc-rio.br/~diego/luasocket/new/
COMMENT=		XML parser for LUA based on expat

MAKEFILE=		${WRKSRC}/makefile
USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblxp.so ${PREFIX}/lib/liblualxp.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/lua/
	${INSTALL_DATA} ${WRKSRC}/test.lua ${PREFIX}/share/examples/lua/lxp.lua

.include "../../textproc/expat/buildlink2.mk"
.include "../../lang/lua/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

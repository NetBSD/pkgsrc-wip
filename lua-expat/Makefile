# $NetBSD: Makefile,v 1.1.1.1 2004/01/29 23:11:59 poppnk Exp $
#

DISTNAME=		luaexpat-1.0a
PKGNAME=		lua-expat
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

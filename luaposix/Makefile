# $NetBSD: Makefile,v 1.4 2005/04/11 21:13:56 tvierling Exp $
#

DISTNAME=		lposix
PKGNAME=		luaposix-1.0
WRKSRC=			${WRKDIR}/posix/
CATEGORIES=		devel
MASTER_SITES=		http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.tecgraf.puc-rio.br/~diego/luasocket/new/
COMMENT=		POSIX library for Lua

USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_DATA} ${WRKSRC}/lposix.so ${PREFIX}/lib/libluaposix.so
	${INSTALL_DATA_DIR} ${PREFIX}/lib/lua/
	${INSTALL_DATA} ${WRKSRC}/*.lua ${PREFIX}/lib/lua/

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

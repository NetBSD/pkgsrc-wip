# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 23:28:43 poppnk Exp $
#

DISTNAME=		lposix
PKGNAME=		luaposix-1.0
WRKSRC=			${WRKDIR}/posix/
CATEGORIES=		wip
MASTER_SITES=		http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.tecgraf.puc-rio.br/~diego/luasocket/new/
COMMENT=		POSIX library for Lua

USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/lposix.so ${PREFIX}/lib/libluaposix.so
	${INSTALL_DATA_DIR} ${PREFIX}/lib/lua/
	${INSTALL_DATA} ${WRKSRC}/*.lua ${PREFIX}/lib/lua/

.include "../../lang/lua/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

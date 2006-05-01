# $NetBSD: Makefile,v 1.6 2006/05/01 01:32:08 shattered Exp $
#

DISTNAME=		lposix
PKGNAME=		luaposix-1.0
WRKSRC=			${WRKDIR}/posix/
CATEGORIES=		devel
MASTER_SITES=		http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/
COMMENT=		POSIX library for Lua

USE_TOOLS+=		gmake

do-install:
	${INSTALL_DATA} ${WRKSRC}/lposix.so ${PREFIX}/lib/libluaposix.so
	${INSTALL_DATA_DIR} ${PREFIX}/lib/lua/
	${INSTALL_DATA} ${WRKSRC}/*.lua ${PREFIX}/lib/lua/

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.8 2007/06/30 21:56:05 corecode Exp $
#

DISTNAME=		lposix
PKGNAME=		luaposix-1.0
CATEGORIES=		devel
MASTER_SITES=		http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/5.0/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/
COMMENT=		POSIX library for Lua

WRKSRC=			${WRKDIR}/posix/
BUILD_TARGET=		lposix.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/lposix.so ${PREFIX}/lib/lua/5.1/posix.so

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

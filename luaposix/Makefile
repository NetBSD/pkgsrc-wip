# $NetBSD: Makefile,v 1.10 2012/10/03 09:10:44 asau Exp $
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
#TEST_TARGET=		test

INSTALLATION_DIRS+=	${LUA_CDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/lposix.so ${DESTDIR}${PREFIX}/${LUA_CDIR}/posix.so

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"

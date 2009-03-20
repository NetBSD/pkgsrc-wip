# $NetBSD: Makefile,v 1.9 2009/03/20 13:50:51 cheusov Exp $
#

DISTNAME=		lposix
PKGNAME=		luaposix-1.0
CATEGORIES=		devel
MASTER_SITES=		http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/5.0/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/
COMMENT=		POSIX library for Lua

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/posix/
BUILD_TARGET=		lposix.so
#TEST_TARGET=		test

INSTALLATION_DIRS+=	${LUA_CDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/lposix.so ${DESTDIR}${PREFIX}/${LUA_CDIR}/posix.so

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
